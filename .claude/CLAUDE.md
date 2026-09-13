# math_diverse — Claude Context

Programme console écrit entre 2010 et 2014 pendant les études de l'auteur, sous
Dev-C++ 5.11 / TDM-GCC 4.9.2 32 bits. Un menu de calculs (équations, déterminant,
factorielle, développement limité, tri, sinus) et quatre jeux : Morpion, Snake,
un Tetris et les Allumettes. **La valeur est historique : on le fait vivre, on ne
le refait pas.**

## Ce que le programme est, et pourquoi ça décide du portage

Contrairement à [Tetris-classic](https://github.com/aminekun90/Tetris-classic), il
n'utilise **pas** de buffer d'écran. Il écrit avec `printf` et `cout`, se
positionne avec `gotoxy`, colore avec `textcolor`, et appelle **`system("cls")`
soixante-deux fois**. La bonne cible n'est donc pas ncurses mais les **séquences
ANSI et termios** — plus simple, et fidèle à ce que le programme croit faire.

`platform/compat.{h,c}` fournit, sur non-Windows :
- l'API `conio.h` (`getch`, `kbhit`, `gotoxy`, `clrscr`, `textcolor`, `wherex`…)
- le sous-ensemble Win32 utilisé (`SetConsoleCursorPosition`, `GetKeyState`,
  `GetTickCount`, `SYSTEMTIME`, `PlaySound`…)
- la traduction des 91 appels à `system()`
- un `printf` qui convertit la sortie CP850 en UTF-8

## Pièges

**Le code est en CP850, pas en CP437ni en Latin-1.** L'auteur écrit ses accents en
codes numériques : `printf("%c Propos.", 183)`. En CP437, 183 donne `╖` ; en
**CP850**, il donne `À`. C'est CP850, la page de code par défaut d'un Windows
français. La table de conversion est générée par le codec Python `cp850`, pas
saisie à la main.

**Les sources mélangent deux encodages.** Le texte accentué a été tapé en CP1252
(`é` = 233), mais les caractères de cadre sont des octets CP850 (`═` = 205,
`║` = 186, `╔` = 201…). Une conversion en bloc depuis ISO-8859-1 rend le texte
correct **et casse les cadres**, qui deviennent `ÉÍÍÍ»`. Les deux ont dû être
traités séparément. **Ne jamais reconvertir ces fichiers en bloc.**

**Le `printf` de compat ne traduit que les octets isolés.** Il laisse passer les
séquences UTF-8 valides — sinon les littéraux déjà convertis (« repensés ») se
retrouveraient corrompus à leur tour. La détection de séquence UTF-8 valide est
le cœur de la fonction, pas un détail.

**Le menu lit `getch()` en scancodes Windows.** Une flèche y rend `0xE0` puis
`72`/`80`, en **deux appels**. Le code compare directement à 72 et 80 dans sa
boucle. `platform/compat.c` reproduit ce protocole en deux temps ; rendre
directement le scancode casserait la navigation. À noter, `diverse.h` définit
`HAUT` à 80 et `BAS` à 72 — c'est inversé par rapport à la convention Windows,
mais c'est le comportement d'origine : ne pas « corriger ».

**Le Snake sonde le clavier, il ne le lit pas.** `isKeyPressed` appelle
`GetKeyState`, qui n'a pas d'équivalent POSIX. La compat tient une **fenêtre de
rémanence de 150 ms** : la dernière touche décodée compte comme enfoncée pendant
ce délai, ce que la répétition automatique du terminal entretient.

**`system()` est redéfini en macro.** `compat.h` fait `#define system
MathDiverseSystem` pour traduire `cls`, `pause`, `title …`, `start …exe` et
`mkdir` sans toucher aux 91 sites d'appel. Dans `compat.c`, il faut `#undef
system` avant d'appeler le vrai — sinon récursion infinie.

**Deux fonctions C appelées depuis du C++.** `Allumette` (allumettes.c) et
`tictactoe` (Morpion/tictac.c) n'avaient pas de `extern "C"` dans leur en-tête :
l'éditeur de liens cherchait un symbole décoré. Corrigé dans `alumette.h` et
`Morpion/tictactoe.h`.

**`={NULL}` comme initialiseur de tableau.** `Morpion/morpion.c` initialisait des
tableaux de `char` et de `int` avec `NULL`. MinGW le tolérait (`NULL` valait `0`) ;
clang refuse (`(void*)0`). Remplacé par `{0}`, ce que l'auteur voulait dire.

**`"MathDiverse "VER""`** — un littéral collé à une macro. C++11 exige une espace,
sinon `invalid suffix on literal`.

## Commandes (vérifiées sur macOS arm64)
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/MathDiverse
```
Windows garde le code d'origine : `cmake -B build -A Win32`.

Le programme lit `tetris.wav` et `a.xm` dans le répertoire courant ; CMake les
recopie à côté de l'exécutable.

## Fichiers hors build
`curl.c`, `download.c` (téléchargement jamais branché), `altconio.h`, `myconio.*`
(conio de secours pour Dev-C++), `snake/game-ASUS.cpp` (variante) et les binaires
d'époque `MathDiverse.exe.Manifest`, `Morpion/data.dll`. Ils ne sont dans aucune
unité de `MathDiverse.dev` et ne sont pas compilés.

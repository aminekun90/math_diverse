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

## Bugs corrigés, et pourquoi c'étaient bien des bugs

Les corrections ci-dessous ne sont pas de la modernisation : ce sont des
résultats faux ou du comportement indéfini. MinGW 4.9 ne les signalait pas,
clang les voit tous.

| Où | Le bug |
|-|-|
| `eq2()` | `(-b+sqrt(d))/2*a` vaut `((-b+√d)/2)·a`, **pas** `(-b+√d)/(2a)`. Toute équation avec a ≠ 1 donnait une racine fausse. Idem pour la racine double, `-b/2*a` |
| `eq2()` | aucun test de `a == 0` : division par zéro sur une équation qui n'est pas du second degré |
| `eq1()` | `result` n'était affecté que si `b != 0`, et affiché non initialisé sinon. Le message confondait les trois cas dégénérés — avec a ≠ 0 et b = 0, la solution est x = 0, ce n'est pas une erreur |
| `fact()` | le tampon global `n` n'était jamais remis à `"1"` : un second calcul repartait de 1000!. C'est la limitation que l'auteur avait notée à l'écran. Corrigée, le garde-fou « une seule fois par session » a été retiré |
| 8 fonctions | déclarées `int`, sans `return` — comportement indéfini en C++ |
| `getch()` | rendait 10 au lieu de 13 pour Entrée : `ICRNL` n'était pas désactivé, le tty convertissait CR en LF et le menu ne reconnaissait plus la touche |

Le tri à bulles et l'indentation trompeuse signalés par clang aux lignes 374 et
732 **ne sont pas** des bugs : la logique est correcte, seul le formatage
trompe.

## Limites numériques des séries — mesurées, puis levées

La version d'origine calculait chaque terme par `pow(x,k)/fact2(k)`. Trois
limites, toutes mesurées avant correction :

| Cas | Avant | Exact |
|-|-|-|
| `sin(3600°)` rang 40 | 2,88 × 10²⁴ | ≈ 0 |
| `sin(36000°)` rang 40 | 7,63 × 10¹⁰⁵ | ≈ 0 |
| `exp(−20)` rang 60 | 3,43 × 10⁻⁵ | 2,06 × 10⁻⁹ |
| `exp(−40)` rang 60 | 6,35 × 10¹³ | 4,25 × 10⁻¹⁸ |
| `fact2(171)` | `inf` | — |

Trois causes distinctes :

1. **`fact2` déborde le `double` au-delà de 170!** Les termes de rang supérieur
   devenaient `0` par division par l'infini, et la série cessait silencieusement
   de progresser. Aucun message, aucun NaN — juste un plafond invisible.
2. **Aucune réduction d'angle.** `sin` et `cos` sont 360-périodiques, mais la
   série de Taylor est centrée en 0 : pour un grand angle, les termes
   intermédiaires deviennent énormes et s'annulent mal.
3. **Annulation catastrophique sur `exp(x)` avec x < 0.** La série alternée perd
   tous ses chiffres significatifs.

Les corrections, dans `serie_sin`, `serie_cos`, `serie_exp`, `serie_ln1p` et
`reduire_angle` :

- **calcul par récurrence** — `terme_k = terme_(k−1) × facteur`. Ni puissance ni
  factorielle n'apparaissent : rien ne peut déborder, et c'est linéaire au lieu
  de quadratique. `sin(30°)` au rang 1000 marche désormais.
- **réduction de l'angle** dans ]−180, 180] avant conversion en radians. C'est
  exact, pas une approximation : la fonction est périodique.
- **`exp(x)` avec x < 0** calcule `exp(|x|)` puis inverse.

`fact2` est conservée — elle est déclarée dans `diverse.h` — mais les séries ne
s'en servent plus. **Ne pas la réintroduire dans un développement limité.**

La tangente n'existait pas ; `calctan` la calcule comme quotient des deux séries,
avec refus explicite quand `cos` s'annule.

## Calculs ajoutés en 2026

`calcexp` (c'était l'entrée « Bientôt » depuis 2014), `calccos`, `calctan`, `calcln`,
`pgcdppcm`, `conversion` (bases 2/8/10/16), `stats` (moyenne, médiane,
variance, écart-type) et `systeme2` (Cramer). Ils suivent le style de la
maison : accents en codes CP850 via `%c`, pour rester lisibles sur la console
Windows comme sur un terminal UTF-8.

Les trois menus concernés ont été réécrits pour les accueillir. **Attention aux
bornes** : chaque menu a un tableau `t[]` de couleurs dont le dernier élément
est la ligne `[ESCAPE]`, et la garde `if(choix==HAUT && i!=N)` doit pointer sur
ce dernier index — sinon la navigation se bloque ou déborde.

## Commandes (vérifiées sur macOS arm64)
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/MathDiverse
```
Windows garde le code d'origine : `cmake -B build -A Win32`.

Le programme lit `tetris.wav` et `a.xm` dans le répertoire courant ; CMake les
recopie à côté de l'exécutable.

## L'enveloppe macOS (`macos/`)

`MathDiverse.app` est une fenêtre SwiftUI contenant un émulateur de terminal
(**SwiftTerm**) dans lequel tourne le binaire. Même montage que
Tetris-classic — `DEVELOPER_DIR` obligatoire pour le shader Metal, délégué
séparé plutôt que sous-classe de `LocalProcessTerminalView`.

```bash
./macos/make-app.sh && open macos/MathDiverse.app
```

## Fichiers hors build
`curl.c`, `download.c` (téléchargement jamais branché), `altconio.h`, `myconio.*`
(conio de secours pour Dev-C++), `snake/game-ASUS.cpp` (variante) et les binaires
d'époque `MathDiverse.exe.Manifest`, `Morpion/data.dll`. Ils ne sont dans aucune
unité de `MathDiverse.dev` et ne sont pas compilés.

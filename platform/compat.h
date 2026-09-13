// Couche de compatibilité POSIX pour MathDiverse (2010-2014, Dev-C++ / TDM-GCC).
//
// Le programme n'utilise pas de buffer d'écran comme Tetris-classic : il écrit
// avec printf et cout, se positionne avec gotoxy, colore avec textcolor, et
// appelle system("cls") soixante-deux fois. La bonne cible n'est donc pas
// ncurses mais les séquences ANSI et termios — c'est plus simple, et c'est
// fidèle à ce que le programme croit faire.
//
// Jamais inclus sous Windows : là-bas, le code d'origine compile tel quel.
#ifndef MATHDIVERSE_COMPAT_H
#define MATHDIVERSE_COMPAT_H
#ifndef _WIN32

/* En-têtes C : compat.h est inclus depuis des .c comme depuis des .cpp. */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------ types */

typedef short          SHORT;
typedef unsigned short WORD;
typedef unsigned int   DWORD;
typedef int            BOOL;
typedef unsigned char  BYTE;
typedef void*          HANDLE;
typedef void*          HWND;
typedef const char*    LPCSTR;

#ifndef TRUE
#define TRUE  1
#define FALSE 0
#endif

typedef struct { SHORT X; SHORT Y; } COORD;
typedef struct { SHORT Left; SHORT Top; SHORT Right; SHORT Bottom; } SMALL_RECT;

typedef struct {
    COORD      dwSize;
    COORD      dwCursorPosition;
    WORD       wAttributes;
    SMALL_RECT srWindow;
    COORD      dwMaximumWindowSize;
} CONSOLE_SCREEN_BUFFER_INFO;

typedef struct { DWORD dwSize; BOOL bVisible; } CONSOLE_CURSOR_INFO;

typedef struct {
    WORD wYear, wMonth, wDayOfWeek, wDay, wHour, wMinute, wSecond, wMilliseconds;
} SYSTEMTIME;

/* -------------------------------------------------------------- constantes */

#define FOREGROUND_BLUE      0x0001
#define FOREGROUND_GREEN     0x0002
#define FOREGROUND_RED       0x0004
#define FOREGROUND_INTENSITY 0x0008
#define BACKGROUND_BLUE      0x0010
#define BACKGROUND_GREEN     0x0020
#define BACKGROUND_RED       0x0040
#define BACKGROUND_INTENSITY 0x0080

#define STD_INPUT_HANDLE  ((DWORD)-10)
#define STD_OUTPUT_HANDLE ((DWORD)-11)

/* Codes de touches virtuelles, restreints à ceux que le programme lit. */
#define VK_RETURN 0x0D
#define VK_ESCAPE 0x1B
#define VK_SPACE  0x20
#define VK_LEFT   0x25
#define VK_UP     0x26
#define VK_RIGHT  0x27
#define VK_DOWN   0x28

#define SND_ASYNC    0x0001
#define SND_FILENAME 0x00020000
#define SND_LOOP     0x0008

/* --------------------------------------------------- sous-ensemble Win32 */

HANDLE GetStdHandle(DWORD which);
BOOL   SetConsoleCursorPosition(HANDLE h, COORD pos);
BOOL   SetConsoleTextAttribute(HANDLE h, WORD attributes);
BOOL   GetConsoleScreenBufferInfo(HANDLE h, CONSOLE_SCREEN_BUFFER_INFO* info);
BOOL   SetConsoleCursorInfo(HANDLE h, const CONSOLE_CURSOR_INFO* info);
BOOL   FillConsoleOutputCharacterA(HANDLE h, char c, DWORD len, COORD at, DWORD* written);
BOOL   FlushConsoleInputBuffer(HANDLE h);
HWND   GetConsoleWindow(void);
BOOL   MoveWindow(HWND w, int x, int y, int width, int height, BOOL repaint);
void   Sleep(DWORD milliseconds);
void   GetSystemTime(SYSTEMTIME* out);
void   GetLocalTime(SYSTEMTIME* out);
DWORD  GetTickCount(void);

/* Build MBCS : sous Windows TEXT("x") vaut "x". */
#ifndef TEXT
#define TEXT(x) x
#endif

/* Le snake sonde le clavier au lieu de le lire. Sans état clavier global sous
   POSIX, on tient une fenêtre de rémanence : la dernière touche décodée reste
   « enfoncée » pendant un court instant, ce qui reproduit le comportement
   d'une touche maintenue. */
SHORT GetKeyState(int virtualKey);
SHORT GetAsyncKeyState(int virtualKey);

BOOL PlaySoundA(LPCSTR sound, void* module, DWORD flags);
#define PlaySound PlaySoundA

#define FillConsoleOutputCharacter FillConsoleOutputCharacterA

/* --------------------------------------------------------------- conio.h */

int  getch(void);
int  getche(void);
int  kbhit(void);
void gotoxy(int x, int y);
void clrscr(void);
void clreol(void);
void textcolor(int color);
void textbackground(int color);
int  wherex(void);
int  wherey(void);

#define _NOCURSOR     0
#define _SOLIDCURSOR  1
#define _NORMALCURSOR 2
void _setcursortype(int type);

/* ------------------------------------------------------- system() traduit */

/* Le programme appelle system() 91 fois : « cls », « pause », « title … »,
   « start …exe ». Aucune de ces commandes n'existe hors Windows. Plutôt que
   de toucher 91 sites d'appel, on les traduit ici. */
int MathDiverseSystem(const char* command);

/* Le programme écrit ses accents en codes CP850 — la page de code de la
   console Windows — via printf("%c", 136) et consorts. Sur un terminal UTF-8
   ce sont des octets invalides. Ce printf traduit les octets isolés >= 128
   depuis CP850, en laissant passer les séquences UTF-8 déjà valides des
   littéraux du source. */
int MathDiversePrintf(const char* format, ...);
#define printf MathDiversePrintf
#define system MathDiverseSystem

#ifdef __cplusplus
}
#endif

#endif /* !_WIN32 */
#endif /* MATHDIVERSE_COMPAT_H */

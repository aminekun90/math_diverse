/* Implémentation ANSI + termios de la couche de compatibilité MathDiverse. */
#ifndef _WIN32

#include "compat.h"

/* system() est redéfini en macro par compat.h : on récupère le vrai. */
#undef system

#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/select.h>
#include <sys/time.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

/* =========================================================== mode terminal */

static struct termios g_savedTermios;
static int  g_rawActive = 0;
static int  g_termSaved = 0;

static void restoreTerminal(void)
{
    if (g_rawActive && g_termSaved) {
        tcsetattr(STDIN_FILENO, TCSANOW, &g_savedTermios);
        g_rawActive = 0;
    }
    fputs("\033[0m\033[?25h", stdout);   /* couleurs et curseur rendus */
    fflush(stdout);
}

/* Mode caractère par caractère, sans écho — l'équivalent de ce que conio
   offrait sous DOS. Restauré à la sortie du programme. */
static void enterRaw(void)
{
    struct termios raw;

    if (g_rawActive) return;
    if (!isatty(STDIN_FILENO)) return;

    if (!g_termSaved) {
        if (tcgetattr(STDIN_FILENO, &g_savedTermios) != 0) return;
        g_termSaved = 1;
        atexit(restoreTerminal);
    }

    raw = g_savedTermios;
    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_cc[VMIN]  = 1;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    g_rawActive = 1;
}

static int readByteBlocking(void)
{
    unsigned char c;
    ssize_t n;
    enterRaw();
    do { n = read(STDIN_FILENO, &c, 1); } while (n < 0 && errno == EINTR);
    return (n == 1) ? (int)c : -1;
}

static int readByteImmediate(void)
{
    unsigned char c;
    fd_set fds;
    struct timeval tv;
    ssize_t n;

    enterRaw();
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    if (select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) <= 0) return -1;
    n = read(STDIN_FILENO, &c, 1);
    return (n == 1) ? (int)c : -1;
}

/* ============================================================== couleurs */

/* L'index de couleur DOS et les bits FOREGROUND_* de Windows sont le même
   encodage : bit0 bleu, bit1 vert, bit2 rouge, bit3 intensité. textcolor(n)
   et SetConsoleTextAttribute(n) désignent donc la même chose. */
static int g_fg = 7;
static int g_bg = 0;

static void emitColor(void)
{
    int fgBase = (g_fg & 8) ? 90 : 30;
    int bgBase = (g_bg & 8) ? 100 : 40;
    int fgCode = ((g_fg & 4) ? 1 : 0) | ((g_fg & 2) ? 2 : 0) | ((g_fg & 1) ? 4 : 0);
    int bgCode = ((g_bg & 4) ? 1 : 0) | ((g_bg & 2) ? 2 : 0) | ((g_bg & 1) ? 4 : 0);
    printf("\033[%d;%dm", fgBase + fgCode, bgBase + bgCode);
    fflush(stdout);
}

void textcolor(int color)      { g_fg = color & 0x0F; emitColor(); }
void textbackground(int color) { g_bg = color & 0x0F; emitColor(); }

/* ============================================================ positionnement */

static int g_curX = 1;   /* 1-based, comme gotoxy sous DOS */
static int g_curY = 1;

void gotoxy(int x, int y)
{
    if (x < 1) x = 1;
    if (y < 1) y = 1;
    g_curX = x;
    g_curY = y;
    printf("\033[%d;%dH", y, x);
    fflush(stdout);
}

int wherex(void) { return g_curX; }
int wherey(void) { return g_curY; }

void clrscr(void)
{
    printf("\033[2J\033[H");
    fflush(stdout);
    g_curX = g_curY = 1;
}

void clreol(void) { fputs("\033[K", stdout); fflush(stdout); }

void _setcursortype(int type)
{
    fputs(type == _NOCURSOR ? "\033[?25l" : "\033[?25h", stdout);
    fflush(stdout);
}

/* ================================================================ clavier */

/* Windows rend les touches étendues en deux temps : 0xE0 puis le scancode.
   Le menu de MathDiverse compare directement à 72 et 80, en rappelant getch
   dans sa boucle — il faut donc reproduire les deux appels. */
#define SCAN_UP    72
#define SCAN_DOWN  80
#define SCAN_LEFT  75
#define SCAN_RIGHT 77

static int g_pendingScan = 0;

static int scanForFinalByte(int final)
{
    switch (final) {
        case 'A': return SCAN_UP;
        case 'B': return SCAN_DOWN;
        case 'C': return SCAN_RIGHT;
        case 'D': return SCAN_LEFT;
        default:  return 0;
    }
}

int getch(void)
{
    int c;

    if (g_pendingScan) { int s = g_pendingScan; g_pendingScan = 0; return s; }

    c = readByteBlocking();
    if (c < 0) return -1;
    if (c != 27) return c;

    /* Séquence d'échappement : lecture immédiate, les octets suivants sont
       déjà dans le tampon. Rien derrière = un vrai Échap. */
    c = readByteImmediate();
    if (c < 0) return 27;
    if (c != '[' && c != 'O') return 27;

    c = readByteImmediate();
    if (c < 0) return 27;

    g_pendingScan = scanForFinalByte(c);
    return g_pendingScan ? 0xE0 : 27;
}

int getche(void)
{
    int c = getch();
    if (c > 0 && c < 256 && c != 0xE0) { putchar(c); fflush(stdout); }
    return c;
}

int kbhit(void)
{
    fd_set fds;
    struct timeval tv;

    if (g_pendingScan) return 1;
    enterRaw();
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}

/* --------------------------------------- état clavier pour GetKeyState() */

static int    g_lastVk = 0;
static double g_lastVkAt = 0.0;

static double nowSeconds(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

static int vkForScan(int scan)
{
    switch (scan) {
        case SCAN_UP:    return VK_UP;
        case SCAN_DOWN:  return VK_DOWN;
        case SCAN_LEFT:  return VK_LEFT;
        case SCAN_RIGHT: return VK_RIGHT;
        default:         return 0;
    }
}

/* Vide ce qui est disponible et retient la dernière touche reconnue. */
static void pollKeyboard(void)
{
    int c;
    while ((c = readByteImmediate()) >= 0) {
        int vk = 0;
        if (c == 27) {
            int second = readByteImmediate();
            if (second < 0)                        vk = VK_ESCAPE;
            else if (second != '[' && second != 'O') vk = VK_ESCAPE;
            else {
                int final = readByteImmediate();
                vk = (final >= 0) ? vkForScan(scanForFinalByte(final)) : VK_ESCAPE;
            }
        } else if (c == '\r' || c == '\n') {
            vk = VK_RETURN;
        } else if (c == ' ') {
            vk = VK_SPACE;
        } else if (c == 'q' || c == 'Q') {
            vk = VK_ESCAPE;
        }
        if (vk) { g_lastVk = vk; g_lastVkAt = nowSeconds(); }
    }
}

/* Rémanence : une touche compte comme enfoncée pendant 150 ms après sa
   dernière frappe. La répétition automatique du terminal entretient l'état
   tant que la touche reste appuyée. */
#define KEY_HOLD_SECONDS 0.15

SHORT GetKeyState(int virtualKey)
{
    pollKeyboard();
    if (g_lastVk == virtualKey && (nowSeconds() - g_lastVkAt) < KEY_HOLD_SECONDS)
        return (SHORT)-32768;
    return 0;
}

SHORT GetAsyncKeyState(int virtualKey) { return GetKeyState(virtualKey); }

/* ========================================================= console Win32 */

static WORD g_attributes = 7;

HANDLE GetStdHandle(DWORD which)
{
    return (which == STD_INPUT_HANDLE) ? (HANDLE)(size_t)1 : (HANDLE)(size_t)2;
}

BOOL SetConsoleCursorPosition(HANDLE h, COORD pos)
{
    (void)h;
    /* L'API Windows est 0-based, gotoxy est 1-based. */
    gotoxy(pos.X + 1, pos.Y + 1);
    return TRUE;
}

BOOL SetConsoleTextAttribute(HANDLE h, WORD attributes)
{
    (void)h;
    g_attributes = attributes;
    g_fg = attributes & 0x0F;
    g_bg = (attributes >> 4) & 0x0F;
    emitColor();
    return TRUE;
}

BOOL GetConsoleScreenBufferInfo(HANDLE h, CONSOLE_SCREEN_BUFFER_INFO* info)
{
    (void)h;
    if (!info) return FALSE;
    memset(info, 0, sizeof(*info));
    info->dwSize.X = 80;
    info->dwSize.Y = 300;
    info->dwCursorPosition.X = (SHORT)(g_curX - 1);
    info->dwCursorPosition.Y = (SHORT)(g_curY - 1);
    info->wAttributes = g_attributes;
    info->srWindow.Right  = 79;
    info->srWindow.Bottom = 24;
    info->dwMaximumWindowSize.X = 80;
    info->dwMaximumWindowSize.Y = 25;
    return TRUE;
}

BOOL SetConsoleCursorInfo(HANDLE h, const CONSOLE_CURSOR_INFO* info)
{
    (void)h;
    if (!info) return FALSE;
    _setcursortype(info->bVisible ? _NORMALCURSOR : _NOCURSOR);
    return TRUE;
}

BOOL FillConsoleOutputCharacterA(HANDLE h, char c, DWORD len, COORD at, DWORD* written)
{
    DWORD i;
    (void)h;
    gotoxy(at.X + 1, at.Y + 1);
    for (i = 0; i < len; i++) putchar(c);
    fflush(stdout);
    if (written) *written = len;
    return TRUE;
}

BOOL FlushConsoleInputBuffer(HANDLE h)
{
    (void)h;
    g_pendingScan = 0;
    while (readByteImmediate() >= 0) { }
    return TRUE;
}

HWND GetConsoleWindow(void) { return NULL; }
BOOL MoveWindow(HWND w, int x, int y, int width, int height, BOOL repaint)
{
    (void)w; (void)x; (void)y; (void)width; (void)height; (void)repaint;
    return TRUE;   /* un terminal ne se déplace pas */
}

void Sleep(DWORD milliseconds)
{
    struct timespec ts;
    ts.tv_sec  = (time_t)(milliseconds / 1000);
    ts.tv_nsec = (long)((milliseconds % 1000) * 1000000L);
    nanosleep(&ts, NULL);
}

static void fillSystemTime(SYSTEMTIME* out, const struct tm* t)
{
    if (!out) return;
    out->wYear         = (WORD)(t->tm_year + 1900);
    out->wMonth        = (WORD)(t->tm_mon + 1);
    out->wDayOfWeek    = (WORD)t->tm_wday;
    out->wDay          = (WORD)t->tm_mday;
    out->wHour         = (WORD)t->tm_hour;
    out->wMinute       = (WORD)t->tm_min;
    out->wSecond       = (WORD)t->tm_sec;
    out->wMilliseconds = 0;
}

void GetSystemTime(SYSTEMTIME* out)
{
    time_t now = time(NULL);
    struct tm t;
    gmtime_r(&now, &t);
    fillSystemTime(out, &t);
}

void GetLocalTime(SYSTEMTIME* out)
{
    time_t now = time(NULL);
    struct tm t;
    localtime_r(&now, &t);
    fillSystemTime(out, &t);
}

/* Millisecondes depuis le démarrage du programme — Windows compte depuis le
   démarrage de la machine, mais seuls les écarts sont utilisés. */
DWORD GetTickCount(void)
{
    static double origin = 0.0;
    double now = nowSeconds();
    if (origin == 0.0) origin = now;
    return (DWORD)((now - origin) * 1000.0);
}

/* ==================================================================== son */

/* Deux appels seulement, pour tetris.wav. On délègue au lecteur du système
   s'il existe ; sinon le jeu tourne en silence, sans erreur. */
BOOL PlaySoundA(LPCSTR sound, void* module, DWORD flags)
{
    static const char* players[] = { "afplay", "paplay", "aplay", NULL };
    char command[512];
    int i;

    (void)module;
    if (!sound) return TRUE;   /* PlaySound(NULL, …) = arrêter le son */

    for (i = 0; players[i]; i++) {
        snprintf(command, sizeof command, "command -v %s >/dev/null 2>&1", players[i]);
        if (system(command) == 0) {
            snprintf(command, sizeof command, "%s '%s' >/dev/null 2>&1 %s",
                     players[i], sound, (flags & SND_ASYNC) ? "&" : "");
            if (system(command) == -1) return FALSE;
            return TRUE;
        }
    }
    return TRUE;
}

/* ================================================ sortie CP850 -> UTF-8 */

static const char* const kCp850[128] = {
    "\xc3\x87",   /* 128  Ç */
    "\xc3\xbc",   /* 129  ü */
    "\xc3\xa9",   /* 130  é */
    "\xc3\xa2",   /* 131  â */
    "\xc3\xa4",   /* 132  ä */
    "\xc3\xa0",   /* 133  à */
    "\xc3\xa5",   /* 134  å */
    "\xc3\xa7",   /* 135  ç */
    "\xc3\xaa",   /* 136  ê */
    "\xc3\xab",   /* 137  ë */
    "\xc3\xa8",   /* 138  è */
    "\xc3\xaf",   /* 139  ï */
    "\xc3\xae",   /* 140  î */
    "\xc3\xac",   /* 141  ì */
    "\xc3\x84",   /* 142  Ä */
    "\xc3\x85",   /* 143  Å */
    "\xc3\x89",   /* 144  É */
    "\xc3\xa6",   /* 145  æ */
    "\xc3\x86",   /* 146  Æ */
    "\xc3\xb4",   /* 147  ô */
    "\xc3\xb6",   /* 148  ö */
    "\xc3\xb2",   /* 149  ò */
    "\xc3\xbb",   /* 150  û */
    "\xc3\xb9",   /* 151  ù */
    "\xc3\xbf",   /* 152  ÿ */
    "\xc3\x96",   /* 153  Ö */
    "\xc3\x9c",   /* 154  Ü */
    "\xc3\xb8",   /* 155  ø */
    "\xc2\xa3",   /* 156  £ */
    "\xc3\x98",   /* 157  Ø */
    "\xc3\x97",   /* 158  × */
    "\xc6\x92",   /* 159  ƒ */
    "\xc3\xa1",   /* 160  á */
    "\xc3\xad",   /* 161  í */
    "\xc3\xb3",   /* 162  ó */
    "\xc3\xba",   /* 163  ú */
    "\xc3\xb1",   /* 164  ñ */
    "\xc3\x91",   /* 165  Ñ */
    "\xc2\xaa",   /* 166  ª */
    "\xc2\xba",   /* 167  º */
    "\xc2\xbf",   /* 168  ¿ */
    "\xc2\xae",   /* 169  ® */
    "\xc2\xac",   /* 170  ¬ */
    "\xc2\xbd",   /* 171  ½ */
    "\xc2\xbc",   /* 172  ¼ */
    "\xc2\xa1",   /* 173  ¡ */
    "\xc2\xab",   /* 174  « */
    "\xc2\xbb",   /* 175  » */
    "\xe2\x96\x91",   /* 176  ░ */
    "\xe2\x96\x92",   /* 177  ▒ */
    "\xe2\x96\x93",   /* 178  ▓ */
    "\xe2\x94\x82",   /* 179  │ */
    "\xe2\x94\xa4",   /* 180  ┤ */
    "\xc3\x81",   /* 181  Á */
    "\xc3\x82",   /* 182  Â */
    "\xc3\x80",   /* 183  À */
    "\xc2\xa9",   /* 184  © */
    "\xe2\x95\xa3",   /* 185  ╣ */
    "\xe2\x95\x91",   /* 186  ║ */
    "\xe2\x95\x97",   /* 187  ╗ */
    "\xe2\x95\x9d",   /* 188  ╝ */
    "\xc2\xa2",   /* 189  ¢ */
    "\xc2\xa5",   /* 190  ¥ */
    "\xe2\x94\x90",   /* 191  ┐ */
    "\xe2\x94\x94",   /* 192  └ */
    "\xe2\x94\xb4",   /* 193  ┴ */
    "\xe2\x94\xac",   /* 194  ┬ */
    "\xe2\x94\x9c",   /* 195  ├ */
    "\xe2\x94\x80",   /* 196  ─ */
    "\xe2\x94\xbc",   /* 197  ┼ */
    "\xc3\xa3",   /* 198  ã */
    "\xc3\x83",   /* 199  Ã */
    "\xe2\x95\x9a",   /* 200  ╚ */
    "\xe2\x95\x94",   /* 201  ╔ */
    "\xe2\x95\xa9",   /* 202  ╩ */
    "\xe2\x95\xa6",   /* 203  ╦ */
    "\xe2\x95\xa0",   /* 204  ╠ */
    "\xe2\x95\x90",   /* 205  ═ */
    "\xe2\x95\xac",   /* 206  ╬ */
    "\xc2\xa4",   /* 207  ¤ */
    "\xc3\xb0",   /* 208  ð */
    "\xc3\x90",   /* 209  Ð */
    "\xc3\x8a",   /* 210  Ê */
    "\xc3\x8b",   /* 211  Ë */
    "\xc3\x88",   /* 212  È */
    "\xc4\xb1",   /* 213  ı */
    "\xc3\x8d",   /* 214  Í */
    "\xc3\x8e",   /* 215  Î */
    "\xc3\x8f",   /* 216  Ï */
    "\xe2\x94\x98",   /* 217  ┘ */
    "\xe2\x94\x8c",   /* 218  ┌ */
    "\xe2\x96\x88",   /* 219  █ */
    "\xe2\x96\x84",   /* 220  ▄ */
    "\xc2\xa6",   /* 221  ¦ */
    "\xc3\x8c",   /* 222  Ì */
    "\xe2\x96\x80",   /* 223  ▀ */
    "\xc3\x93",   /* 224  Ó */
    "\xc3\x9f",   /* 225  ß */
    "\xc3\x94",   /* 226  Ô */
    "\xc3\x92",   /* 227  Ò */
    "\xc3\xb5",   /* 228  õ */
    "\xc3\x95",   /* 229  Õ */
    "\xc2\xb5",   /* 230  µ */
    "\xc3\xbe",   /* 231  þ */
    "\xc3\x9e",   /* 232  Þ */
    "\xc3\x9a",   /* 233  Ú */
    "\xc3\x9b",   /* 234  Û */
    "\xc3\x99",   /* 235  Ù */
    "\xc3\xbd",   /* 236  ý */
    "\xc3\x9d",   /* 237  Ý */
    "\xc2\xaf",   /* 238  ¯ */
    "\xc2\xb4",   /* 239  ´ */
    "\xc2\xad",   /* 240  ­ */
    "\xc2\xb1",   /* 241  ± */
    "\xe2\x80\x97",   /* 242  ‗ */
    "\xc2\xbe",   /* 243  ¾ */
    "\xc2\xb6",   /* 244  ¶ */
    "\xc2\xa7",   /* 245  § */
    "\xc3\xb7",   /* 246  ÷ */
    "\xc2\xb8",   /* 247  ¸ */
    "\xc2\xb0",   /* 248  ° */
    "\xc2\xa8",   /* 249  ¨ */
    "\xc2\xb7",   /* 250  · */
    "\xc2\xb9",   /* 251  ¹ */
    "\xc2\xb3",   /* 252  ³ */
    "\xc2\xb2",   /* 253  ² */
    "\xe2\x96\xa0",   /* 254  ■ */
    "\xc2\xa0",   /* 255    */
};

/* Longueur d'une séquence UTF-8 valide commençant à p, 0 si ce n'en est pas une. */
static int utf8SequenceLength(const unsigned char* p, size_t remaining)
{
    int need, i;
    if (p[0] < 0xC2 || p[0] > 0xF4) return 0;
    if      ((p[0] & 0xE0) == 0xC0) need = 2;
    else if ((p[0] & 0xF0) == 0xE0) need = 3;
    else if ((p[0] & 0xF8) == 0xF0) need = 4;
    else return 0;
    if ((size_t)need > remaining) return 0;
    for (i = 1; i < need; i++)
        if ((p[i] & 0xC0) != 0x80) return 0;
    return need;
}

static void writeTranslated(const char* text)
{
    const unsigned char* p = (const unsigned char*)text;
    size_t len = strlen(text), i = 0;

    while (i < len) {
        if (p[i] < 0x80) {
            putchar((int)p[i]);
            i++;
        } else {
            int seq = utf8SequenceLength(p + i, len - i);
            if (seq) {
                fwrite(p + i, 1, (size_t)seq, stdout);   /* déjà de l'UTF-8 */
                i += (size_t)seq;
            } else {
                fputs(kCp850[p[i] - 128], stdout);        /* octet CP850 isolé */
                i++;
            }
        }
    }
}

#undef printf
int MathDiversePrintf(const char* format, ...)
{
    char stackBuffer[4096];
    char* buffer = stackBuffer;
    va_list args;
    int needed;

    va_start(args, format);
    needed = vsnprintf(stackBuffer, sizeof stackBuffer, format, args);
    va_end(args);
    if (needed < 0) return needed;

    if ((size_t)needed >= sizeof stackBuffer) {
        buffer = (char*)malloc((size_t)needed + 1);
        if (!buffer) return -1;
        va_start(args, format);
        vsnprintf(buffer, (size_t)needed + 1, format, args);
        va_end(args);
    }

    writeTranslated(buffer);
    fflush(stdout);
    if (buffer != stackBuffer) free(buffer);
    return needed;
}

/* ================================================== traduction de system() */

int MathDiverseSystem(const char* command)
{
    if (!command) return 1;   /* système de commandes disponible */

    if (strcmp(command, "cls") == 0) { clrscr(); return 0; }

    if (strcmp(command, "pause") == 0) {
        printf("Appuyez sur une touche pour continuer...");
        fflush(stdout);
        getch();
        printf("\n");
        return 0;
    }

    if (strncmp(command, "title ", 6) == 0) {
        printf("\033]0;%s\007", command + 6);   /* titre de fenêtre xterm */
        fflush(stdout);
        return 0;
    }

    /* « start X.exe » relançait un exécutable séparé sous Windows. Ici tout
       tient dans un seul binaire : il n'y a rien à lancer. */
    if (strncmp(command, "start ", 6) == 0) return 0;

    if (strncmp(command, "color ", 6) == 0) return 0;

    /* « mkdir txt » se plaint bruyamment quand le dossier existe déjà, en
       plein milieu de l'écran d'accueil. Sous Windows la commande est tout
       aussi bavarde, mais elle écrit dans une console qu'on efface juste
       après ; ici on crée le dossier sans commentaire. */
    if (strncmp(command, "mkdir ", 6) == 0) {
        char quiet[512];
        snprintf(quiet, sizeof quiet, "mkdir -p %s >/dev/null 2>&1", command + 6);
        return system(quiet);
    }

    return system(command);
}

#endif /* !_WIN32 */

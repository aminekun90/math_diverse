#ifndef H_CONSOLE
#define H_CONSOLE

#include <string>
#include <windows.h>

using namespace std;

#define RED FOREGROUND_RED + FOREGROUND_INTENSITY
#define GREEN FOREGROUND_GREEN + FOREGROUND_INTENSITY
#define WHITE FOREGROUND_GREEN + FOREGROUND_RED + FOREGROUND_BLUE + FOREGROUND_INTENSITY
#define BLUE FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_INTENSITY
#define YELLOW FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_INTENSITY
#define GREY FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE

bool isKeyPressed(short key);
void setCursorPos(short x, short y);
void clearConsole();
void setTitle(string newTitle);
void waitForEnter();
string formatNumber(int number);
int Random(int min, int max);
void changeColor(unsigned int ByteColor);
int Distance(int x1, int y1, int x2, int y2);

#endif

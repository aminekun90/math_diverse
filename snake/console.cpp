#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "console.h"

using namespace std;

bool isKeyPressed(short key)
{
     return (GetKeyState(key) < 0);
}

void setCursorPos(short x, short y)
{
  COORD coord = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearConsole()
{
     system("cls");
     changeColor(WHITE);     
}

void setTitle(string newTitle)
{
     string command = "title " + newTitle;
     system(command.c_str());
}

void waitForEnter()
{
    setCursorPos(40, 22);
    changeColor(WHITE);
    cout << "Appuyez sur [ENTREE] pour continuer.";
    while (!isKeyPressed(VK_RETURN))
    {
       Sleep(10);
    }    
}

string formatNumber(int number)
{
    ostringstream os;
    os << number; 
    string sNumber = os.str();
    
    if (sNumber.size() < 5)
       return sNumber;
    
    int pointToAdd = sNumber.size() / 3;
    
    int i = sNumber.size();
    int dat = 0;
    string newNumber = "";
    
    while (i > 0)
    {
        if (dat == 3)
        {
            newNumber = " " + newNumber;
            dat = 0;
        }
        newNumber = sNumber.substr(i - 1, 1) + newNumber;
        dat++;
        i--;
    }
    
    return newNumber;
    
    
}

int Random(int min, int max)
{
    return (rand() % (max - min + 1)) + min;   
}

void changeColor(unsigned int ByteColor)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, ByteColor);
}

int Distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

#include <cstdlib>
#include <iostream>
#include <vector>
#include "menu.h"
#include "snake.h"
#include "console.h"

using namespace std;

void initSnake(int startX, int startY, int snakeSize, vector<int> &snakePosX, vector<int> &snakePosY)
{
    for (int i = 0; i < snakeSize; i++)
    {
        snakePosX.at(i) = startX;
        snakePosY.at(i) = startY - i;
    }
}

bool isSnake(int posX, int posY, int snakeSize, vector<int> &snakePosX, vector<int> &snakePosY)
{
    for (int i = snakeSize - 1; i > 0 ; i--)
    {
        if (posX == snakePosX.at(i) && posY == snakePosY.at(i))
        {
            return true;
        }
    }    
    
    return false;
        
}

void checkMove(int *snakeMoveX, int *snakeMoveY, bool *hasMoved)
{
    if (*hasMoved)
       return;
    
    if (isKeyPressed(VK_UP) && (*snakeMoveY != 1))
    {
       *snakeMoveX = 0;
       *snakeMoveY = -1;
       *hasMoved = true;
       return;
    }
    if (isKeyPressed(VK_DOWN) && (*snakeMoveY != -1))
    {
       *snakeMoveX = 0;
       *snakeMoveY = 1;
       *hasMoved = true;
       return;
    }
    if (isKeyPressed(VK_LEFT) && (*snakeMoveX != 1))
    {
       *snakeMoveX = -1;
       *snakeMoveY = 0;
       *hasMoved = true;
       return;
    }
    if (isKeyPressed(VK_RIGHT) && (*snakeMoveX != -1))
    {
       *snakeMoveX = 1;
       *snakeMoveY = 0;
       *hasMoved = true;
       return;
    }
    if (isKeyPressed(VK_ESCAPE))
    {
    	clearConsole();
    	*hasMoved = false;
    		system("start Mathdiverse.exe");
		exit(0);
    	return;
    }
}

void colorSnake(unsigned int color, int snakeSize, vector<int> &snakePosX, vector<int> &snakePosY)
{
     changeColor(color);
     for (int i = 1; i < snakeSize; i++)
     {
         setCursorPos(snakePosX[i], snakePosY[i]);
         cout << "o";
     }
     setCursorPos(snakePosX[0], snakePosY[0]);
     cout << "O";
}

#include <cstdlib>
#include <iostream>
#include <vector>

#include "snake.h"
#include "apple.h"
#include "console.h"

void GenerateApple(int *appleX, int *appleY, int *bonusType, int *appleLenght, int snakeSize, vector<int> &snakePosX, vector<int> &snakePosY, int mapObject[78][25])
{
    do
    {
        *appleX = Random(3, 75);
        *appleY = Random(5, 21);
    } while (isSnake(*appleX, *appleY, snakeSize, snakePosX, snakePosY) || (mapObject[*appleX][*appleY] >= 1));
    
    *bonusType = 0;
    *appleLenght = 0;
    
    setCursorPos(*appleX, *appleY);
    
    if ((Random(1, 15) == 1) && snakeSize > 10)
    {
        changeColor(YELLOW);
        int Type = Random(1, 3);
        if (Type == 1)
        {
            *appleLenght = Random(-5, -1);
            cout << "!";
        }
        else if (Type == 2)
        {
            *bonusType = 1;
            cout << "$";
        }
        else
        {
            *bonusType = 2;
            cout << "*";
        }
    }
    else if ((Random(1, 15) == 1) && snakeSize > 15)
    {
         changeColor(YELLOW);
         *bonusType = 3;
         cout << "I";//invincible
    }
    else
    {
        changeColor(BLUE);
    
        *appleLenght = Random(1, 6);
        switch (*appleLenght)
        {
               case 1:
               case 2:
                    cout << ".";
                    break;
               case 3:
               case 4:
                    cout << "+";
                    break;
               default:
                    cout << "%";
                    break;
        }
    
    }

}

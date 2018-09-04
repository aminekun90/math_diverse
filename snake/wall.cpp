#include <cstdlib>
#include <iostream>
#include <vector>

#include "snake.h"
#include "wall.h"
#include "console.h"

using namespace std;

void generateWallBase(int mapObject[78][25])
{
    for (int x = 1; x < 78; x++)
    {
        mapObject[x][3] = 1;
        setCursorPos(x, 3);
        cout << "#";
        mapObject[x][23] = 1;
        setCursorPos(x, 23);
        cout << "#";
    }
    for (int y = 3; y < 24; y++)
    {
        mapObject[1][y] = 1;
        setCursorPos(1, y);
        cout << "#";
        mapObject[77][y] = 1;
        setCursorPos(77, y);
        cout << "#";
    }
}

void generateRandomWalls(int mapObject[78][25], vector<int> &snakePosX, vector<int> &snakePosY, int Number)
{
    changeColor(WHITE);
    for (int i = 0; i < Number; i++)
    {
        
        int x = Random(2, 77 - 6);
        int y = Random(4, 23 - 6);

        if (Random(1, 2) == 1) {
            for (int k = x; k < x + Random(3, 6); k++) {
                if ((Distance(snakePosX.at(0), snakePosY.at(0), k, y) > 5) && (mapObject[k][y] == 0) && (!isSnake(k, y, snakePosX.size(), snakePosX, snakePosY)))
                {
                    mapObject[k][y] = 2;
                    setCursorPos(k, y);
                    cout << "#";
                }
            }
        } else {
            for (int k = y; k < y + Random(3, 6); k++) {
                if ((Distance(snakePosX.at(0), snakePosY.at(0), x, k) > 5) && (mapObject[x][k] == 0) && (!isSnake(x, k, snakePosX.size(), snakePosX, snakePosY)))
                {
                    mapObject[x][k] = 2;
                    setCursorPos(x, k);
                    cout << "#";
                }
            }   
        }
        
    }
}


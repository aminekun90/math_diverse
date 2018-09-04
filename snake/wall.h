#ifndef H_WALL
#define H_WALL

#include <vector>
using namespace std;

void generateWallBase(int mapObject[78][25]);
void generateRandomWalls(int mapObject[78][25], vector<int> &snakePosX, vector<int> &snakePosY, int Number);

#endif

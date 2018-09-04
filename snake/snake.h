#ifndef H_SNAKE
#define H_SNAKE

#include <vector>

using namespace std;

void initSnake(int startX, int startY, int snakeSize, vector<int> &snakePosX, vector<int> &snakePosY);
bool isSnake(int posX, int posY, int snakeSize, vector<int> &snakePosX, vector<int> &snakePosY);
void checkMove(int *snakeMoveX, int *snakeMoveY, bool *hasMoved);
void colorSnake(unsigned int color, int snakeSize, vector<int> &snakePosX, vector<int> &snakePosY);

#endif

//#include "stdafx.h"

#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>
#include "tetris.h"
#include "diverse.h"
#include <iostream>
using namespace std;


int max(int x,int y)
{
    if (x>=y)
	return x;
    else if (x<y)
    return y;
}
class Vector
{
public:
   Vector(int x = 0, int y = 0)
      : X(x), Y(y)
   { }

   int X, Y;

   Vector operator + (const Vector &right) const
   {
      return Vector(X + right.X, Y + right.Y);
   }
};

const char *TITLE = "Tetris Hellow-dev 0.1";
const char *SCORE_FILE = "tetrisScore.txt";
const char *FAIL_STR = "GAME OVER!";

const int FIELD_WIDTH = 15, FIELD_HEIGHT = 20;
const int HORIZONTAL_DIVIDE = 4, VERTICAL_DIVIDE = 20;
const int BOARD_WIDTH = 35, BOARD_HEIGHT = FIELD_HEIGHT + HORIZONTAL_DIVIDE + 2;
const Vector FIELD_START((VERTICAL_DIVIDE - FIELD_WIDTH)/2,HORIZONTAL_DIVIDE + 1);
const Vector NEXT_PIECE_POS(VERTICAL_DIVIDE + (BOARD_WIDTH - VERTICAL_DIVIDE)/2,HORIZONTAL_DIVIDE + 4);
const Vector SCORE_POS(VERTICAL_DIVIDE + 2,NEXT_PIECE_POS.Y + 4);

char field[FIELD_HEIGHT * FIELD_WIDTH];
bool exiting = false;
bool downHeld = false;
int score = 0, highScore = 0;

void Reset();

char &GetField(const Vector &pos)
{
   return field[pos.Y*FIELD_WIDTH + pos.X];
}

char &GetField(int x, int y)
{
   return field[y*FIELD_WIDTH + x];
}

void SetConsoleCursor(const Vector &pos)
{
   COORD c = {(short)pos.X, (short)pos.Y};

   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition( h, c );
}

class Piece
{
public:
   Piece()
   { }

   Piece(const Vector &b1, const Vector &b2, const Vector &b3, const Vector &b4)
   {
      Blocks[0] = b1;
      Blocks[1] = b2;
      Blocks[2] = b3;
      Blocks[3] = b4;
   }

   void SetPosition(const Vector &pos)
   {
      Position = pos;
   }

   Vector &GetPosition()
   {
      return Position;
   }

   bool Step()
   {
      ++Position.Y;
      if (Collide())
      {
         --Position.Y;
         Freeze();
         return true;
      }

      return false;
   }

   void Rotate()
   {
      for (int i = 0; i < 4; ++i)
      {
         Vector pos = Blocks[i];
         Blocks[i] = Vector(pos.Y, -pos.X);
      }

      if (Collide())
      {
         UnRotate();
      }
   }

   void UnRotate()
   {
      for (int i = 0; i < 4; ++i)
      {
         Vector pos = Blocks[i];
         Blocks[i] = Vector(-pos.Y, pos.X);
      }
   }

   void Draw(const Vector &fieldStart, bool clamp = true, char character = '#')
   {
      for (int i = 0; i < 4; ++i)
      {
         Vector pos = Position + Blocks[i];
         if (pos.Y >= 0 || !clamp)
         {
            SetConsoleCursor(fieldStart + pos);
            cout<<character;
         }
      }
   }

   void UnDraw(const Vector &fieldStart, bool clamp = true)
   {
      Draw(fieldStart, clamp, ' ');
   }

   bool Collide()
   {
      for (int i = 0; i < 4; ++i)
      {
         Vector pos = Position + Blocks[i];
         if (pos.X < 0 || pos.X >= FIELD_WIDTH || (pos.Y >= 0 && GetField(pos) == '#'))
            return true;
      }

      return false;
   }

private:
   void Freeze()
   {
      for (int i = 0; i < 4; ++i)
         GetField(Position + Blocks[i]) = '#';
   }

   Vector Position;
   Vector Blocks[4];
};

const int PIECE_COUNT = 5;
Piece pieces[PIECE_COUNT];
Piece activePiece, nextPiece;

void SetupPieces()
{
   pieces[0] =  Piece(Vector(0,2), Vector(0,1), Vector(0,0), Vector(0,-1));
   pieces[1] =  Piece(Vector(0,0), Vector(0,1), Vector(1,0), Vector(1,1));
   pieces[2] =  Piece(Vector(-1,0), Vector(0,0), Vector(1,0), Vector(0,-1));
   pieces[3] =  Piece(Vector(-1,1), Vector(-1,0), Vector(0,0), Vector(0,-1));
   pieces[4] =  Piece(Vector(1,1), Vector(1,0), Vector(0,0), Vector(0,-1));
}

int RandInt(int low, int high)
{
   int range = high - low;
   return low + rand() % range;
}

void LoadHighScore()
{
   FILE *file = fopen(SCORE_FILE, "r");

   if (file)
   {
      fscanf(file, "%i", &highScore);
      fclose(file);
   }
}

void SaveHighScore()
{
   FILE *file = fopen(SCORE_FILE, "w");

   if (file)
   {
      fprintf(file, "%i", highScore);
      fclose(file);
   }
}

void Fail()
{
   int failLen = (int)strlen(FAIL_STR);
   Vector pos = FIELD_START + Vector((FIELD_WIDTH - failLen)/2,FIELD_HEIGHT/2);
   SetConsoleCursor(pos);
	color(12,0);
   cout<<FAIL_STR;
	color(15,0);
   while (GetKeyState(VK_SPACE) > -100 && GetKeyState(VK_RETURN) > -100)
   {}

   highScore = max(highScore, score);
   SaveHighScore();

   Reset();
}

void SpawnPiece()
{
   activePiece = nextPiece;
   activePiece.SetPosition(Vector(FIELD_WIDTH/2, 0));

   if (activePiece.Collide())
   {
      Fail();
      return;
   }

   nextPiece.UnDraw(NEXT_PIECE_POS, false);
   nextPiece = pieces[RandInt(0,PIECE_COUNT)];
   nextPiece.Draw(NEXT_PIECE_POS, false);
}

void DrawStatics()
{
   for (int i = 0; i < BOARD_WIDTH; ++i)
   {
      SetConsoleCursor(Vector(i,0));
      cout<<'-';

      SetConsoleCursor(Vector(i,BOARD_HEIGHT));
      cout<<'-';

      SetConsoleCursor(Vector(i,HORIZONTAL_DIVIDE));
      cout<<'-';
   }

   for (int i = 1; i < BOARD_HEIGHT; ++i)
   {
      SetConsoleCursor(Vector(0,i));
      cout<<'|';

      SetConsoleCursor(Vector(BOARD_WIDTH-1,i));
      cout<<'|';

      SetConsoleCursor(Vector(VERTICAL_DIVIDE,max(i, HORIZONTAL_DIVIDE+1)));
      cout<<'|';
   }

   for (int i = 0; i < FIELD_HEIGHT; ++i)
   {
      SetConsoleCursor(FIELD_START + Vector(-1,i));
      cout<<"|";
      SetConsoleCursor(FIELD_START + Vector(FIELD_WIDTH,i));
      cout<<"|";
   }

   int len = (int)strlen(TITLE);
   Vector pos((BOARD_WIDTH - len)/2, HORIZONTAL_DIVIDE/2);

   SetConsoleCursor(pos);
   cout<<TITLE;

   SetConsoleCursor(Vector(SCORE_POS.X, NEXT_PIECE_POS.Y-2));
   cout<<"Next Piece:";

   SetConsoleCursor(SCORE_POS);
   cout<<"Score:";

   SetConsoleCursor(SCORE_POS + Vector(0,3));
   cout<<"High Score:";
}

void DrawScore()
{
   Vector pos = SCORE_POS + Vector(0,1);
   int length = BOARD_WIDTH - pos.X - 1;

   SetConsoleCursor(pos);
   for(int i = 0; i < length; ++i)
      cout<<" ";

   SetConsoleCursor(pos);
   cout<<score;

   pos.Y += 3;

   SetConsoleCursor(pos);
   for(int i = 0; i < length; ++i)
      cout<<" ";

   SetConsoleCursor(pos);
   cout<<highScore;
}

void Reset()
{
   memset(field, 0, sizeof(field));
   memset(field + FIELD_WIDTH * (FIELD_HEIGHT-1), '#', FIELD_WIDTH);

   score = 0;

   DrawStatics();
   DrawScore();

   srand((unsigned int)time(0));
   SpawnPiece();
   SpawnPiece();
}

void ProcessInput()
{
   static bool leftState = false;
   static bool rightState = false;
   static bool upState = false;
   static bool downState = false;

   Vector &pos = activePiece.GetPosition();

   if (GetKeyState(VK_LEFT) < -100)
   {
      if (!leftState)
      {
         --pos.X;
         if (activePiece.Collide())
            ++pos.X;
      }
      leftState = true;
   }
   else
   {
      leftState = false;
   }

   if (GetKeyState(VK_RIGHT) < -100)
   {
      if (!rightState)
      {
         ++pos.X;
         if (activePiece.Collide())
            --pos.X;
      }
      rightState = true;
   }
   else
   {
      rightState = false;
   }

   if (GetKeyState(VK_UP) < -100)
   {
      if (!upState)
         activePiece.Rotate();

      upState = true;
   }
   else
   {
      upState = false;
   }

   if (GetKeyState(VK_DOWN) < -100)
   {
      if (!downState)
         downHeld = true;

      downState = true;
   }
   else
   {
      downState = false;
      downHeld = false;
   }

   if (GetKeyState(VK_ESCAPE) < -100)
   {
      exiting = true;
   }
}

void StepPiece()
{
   if (activePiece.Step())
   {
      SpawnPiece();
      downHeld = false;
   }
}

void CollapseBoard(int rowStart, int rowCnt)
{
   int start = rowStart * FIELD_WIDTH;
   int amount = FIELD_WIDTH * rowCnt;

   memset(field + start, 0, amount);
   memmove(field + amount, field, start);

   score += rowCnt * rowCnt;
   DrawScore();
}

void TestBoard()
{
   int rowStart = 0, rowCnt = 0;

   for (int y = 0; y < FIELD_HEIGHT-1; ++y)
   {
      bool rowFilled = true;

      for (int x = 0; x < FIELD_WIDTH; ++x)
      {
         if (GetField(x, y) != '#')
         {
            rowFilled = false;
            break;
         }
      }

      if (rowFilled)
      {
         ++rowCnt;
      }
      else
      {
         if (rowCnt > 0)
         {
            CollapseBoard(rowStart, rowCnt);
            rowStart += rowCnt;
            rowCnt = 0;
         }
         else
         {
            ++rowStart;
         }
      }
   }

   if (rowCnt > 0)
      CollapseBoard(rowStart, rowCnt);
}

void DoLogic(int dt)
{
   static int time = 0;
   time += dt;

   int stepRate = 300;
   if (time > stepRate)
   {
      StepPiece();
      time -= stepRate;
   }

   if (downHeld)
      StepPiece();

   TestBoard();
}

void Draw()
{
   for(int y = 0; y < FIELD_HEIGHT; ++y)
   {
      SetConsoleCursor(FIELD_START + Vector(0,y));
      for (int x = 0; x < FIELD_WIDTH; ++x)
         cout<<GetField(x,y);
   }

   activePiece.Draw(FIELD_START);
}

void Delay(unsigned long ms)
{
   unsigned long outTime = GetTickCount() + ms;
   while (outTime > GetTickCount())
      ProcessInput();
}

void TET()
{
	exiting=false;
   LoadHighScore();
   SetupPieces();
   Reset();
PlaySound(TEXT("tetris.wav"),NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
  while(!exiting)
   {
   	
      int dt = 50;
      Delay(dt);
      ProcessInput();
      DoLogic(dt);
      Draw();
   }
   PlaySound(NULL, 0, 0);
   return;
}

#ifndef _GreedySnake_
#define _GreedySnake_
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "GreedySnake_judger.h"

using namespace std;
struct GreedySnake_point
{
    int x,y;
    GreedySnake_point *next;
    GreedySnake_point *previous;
};
extern GreedySnake_point* SnakeHeader;
extern char Screen[30][101];
extern char Direction;
extern int Speed;
extern int SnakeLength;
void Print_Screen();
void ScreenInit();
GreedySnake_point* CreatSnake();
void NextGraph();
void ShowSnake();
void keycheck();
void SnakeMove();
void Determine_Speed();
void gotoxy(int, int);
void Print_Graph();
void HideCursor();
#endif

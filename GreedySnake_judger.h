#ifndef _GreedySnake_judger_
#define _GreedySnake_judger_
#include "GreedySnake.h"
struct Fooddef{
    int x,y;
    int FoodCount=0;
};
extern Fooddef Food; 
extern int LoseFlag;
extern int WinFlag;
void CreateFood();
void SnakeLengthen();
void ShowFood();
void JudgeFood();
void JudgeLose_Win();
#endif
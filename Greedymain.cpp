#include "GreedySnake.h"
int main()
{   LoseFlag=WinFlag=0;
    ScreenInit();
    SnakeHeader=CreatSnake();
    CreateFood();
    gotoxy(0,0);
    Print_Screen();
    HideCursor();
    while(1)
    {
    keycheck();
    SnakeMove();
    JudgeFood();
   JudgeLose_Win();
    NextGraph();
    gotoxy(1,1);
    Print_Graph();
    Determine_Speed();
    Sleep(Speed);
   if(LoseFlag==1||WinFlag==1)
    break;
    }
    system("cls");
    if(LoseFlag==1)
    cout<<"You Lose!!!!\n"<<"want to play again? Press enter!";
    if(WinFlag==1)
    cout<<"You Win!!!!\n"<<"want to play again? Press enter!";
    getchar();
    main();
    }
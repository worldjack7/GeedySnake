#include "GreedySnake_judger.h"
int LoseFlag=0;
int WinFlag=0;
Fooddef Food;
void CreateFood(){
    time_t ts;
    unsigned int num=time(&ts);
    srand(num);
    do{
    Food.x=int(rand())%98+1;
    Food.y=int(rand())%28+1;}
    while(Screen[Food.y][Food.x]=='@');
    Food.FoodCount++;
}

void JudgeFood(){
    if(SnakeHeader->x==Food.x&&SnakeHeader->y==Food.y)
    {
    SnakeLengthen();
    CreateFood();
    }
}

void SnakeLengthen(){
    SnakeLength++;
    GreedySnake_point* ptr=SnakeHeader;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=new GreedySnake_point;
    ptr->next->previous=ptr;
    if(ptr->previous->x==ptr->x)
    {ptr->next->x=ptr->x;
    ptr->next->y=2*ptr->y-ptr->previous->y;}
    else
    {ptr->next->y=ptr->y;
    ptr->next->x=2*ptr->x-ptr->previous->x;}
    ptr->next->next=NULL;
}

void ShowFood(){
    Screen[Food.y][Food.x]='$';
}

void JudgeLose_Win(){
   if(Screen[SnakeHeader->y][SnakeHeader->x]=='#'||Screen[SnakeHeader->y][SnakeHeader->x]=='@')
   LoseFlag=1;
   if(SnakeLength==28*98)
   WinFlag==1;
}
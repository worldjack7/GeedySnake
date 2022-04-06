#include "GreedySnake.h"
using namespace std;
GreedySnake_point* SnakeHeader;
char Screen[30][101];
char Direction='d';
int Speed=40;
int SnakeLength=10;

void Print_Screen(){
    for(int i=0;i<=29;i++)
        for(int m=0;m<=100;m++)
            cout<<Screen[i][m];
}

void Print_Graph(){
    for(int i=1;i<=28;i++)
        {for(int m=1;m<=98;m++)
            cout<<Screen[i][m];
            gotoxy(1,i+1);}
}

void NextGraph(){
    ScreenInit();
    ShowFood();
    ShowSnake();
}

void ScreenInit(){
    for(int i=0;i<=29;i++)
    Screen[i][100]='\n';
    for(int i=0;i<=29;i++)
    {
        if(i==0||i==29)
        for(int m=0;m<=99;m++)
        Screen[i][m]='#';
        if(i!=0&&i!=29)
        {
            Screen[i][0]=Screen[i][99]='#';
        for(int m=1;m<=98;m++)
            Screen[i][m]=' ';
           }
    }
}

 GreedySnake_point* CreatSnake(){
    GreedySnake_point* ptr2;
    GreedySnake_point* head=new GreedySnake_point;
    GreedySnake_point* ptr=head;
    for(int i=0;i<10;i++)
    {
        ptr->x=50-i;ptr->y=15;
        if(i!=9)
        {
        ptr2=ptr;
        ptr->next=new GreedySnake_point;
        ptr=ptr->next;
        }
        else
        ptr->next=NULL;
        ptr->previous=ptr2;
    }
    return head;
}

void ShowSnake(){
    GreedySnake_point* ptr=SnakeHeader;
    while(ptr->next!=NULL)
    {
        Screen[ptr->y][ptr->x]='@';
        ptr=ptr->next;
    }
}

void keycheck(){
    if(_kbhit())
    {char keydown=_getch();
    if(keydown=='w'&&Direction=='s'||keydown=='s'&&Direction=='w'||keydown=='a'&&Direction=='d'||keydown=='d'&&Direction=='a')
        return;
    else
        Direction=keydown;}    
}

void SnakeMove(){
    GreedySnake_point *ptr=SnakeHeader;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    while(ptr!=SnakeHeader)
    {
         ptr->x=ptr->previous->x;
         ptr->y=ptr->previous->y;
         ptr=ptr->previous;
    }
    if(Direction=='w')
    SnakeHeader->y-=1;
    if(Direction=='s')
    SnakeHeader->y+=1;
    if(Direction=='a')
    SnakeHeader->x-=1;
    if(Direction=='d')
    SnakeHeader->x+=1;
}

void Determine_Speed(){
    Speed=40/Food.FoodCount;
}

void gotoxy(int x, int y)
{
	HANDLE hout;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
}

void HideCursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false; 
	SetConsoleCursorInfo(handle, &CursorInfo);
}


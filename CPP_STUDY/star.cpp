#include<iostream>
using namespace std;
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
void textcolor(int foreground, int background);
void gotoxy(int, int);

typedef struct {
	int x;
	int y;
} xy;
void twinkle(xy *, int, int);
int main()
{
	int fore, num=0;
	xy xy[30];
	srand((unsigned int)time(0));
	for(int i=0; i<30; i++){
		fore = rand() % 16;
		textcolor(fore, BLACK);
		twinkle(xy+i, rand()%80, rand()%40);
		putchar('*');
	}
	while(1){
		if(num%15 == 0)
			Sleep(rand()%400);
		gotoxy(xy[num].x, xy[num].y);
		putchar(' ');
		Sleep(10);
		fore = rand() % 16;
		textcolor(fore, BLACK);
		twinkle(xy+num, rand()%20, rand()%20);
		putchar('*');
		Sleep(10);
		num = (num+1)%30;
		}
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y){
	COORD Pos = {x-1, y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void twinkle(xy *xy, int x, int y){
	gotoxy(x, y);
	xy->x = x;
	xy->y = y;
}

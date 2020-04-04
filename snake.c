#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct 
{
	int x;
	int y;
	struct Snake* next;
	struct Snake* previous;
} Snake;

//typedef struct
//{
//	int x;
//	int y;
//} Apple;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void create_game_field()
{
	for (int i = 0; i < 40; i++)
	{
		gotoxy(i, 0);
		printf("#");
		gotoxy(i, 20);
		printf("#");
	}

	for (int i = 0; i < 21; i++)
	{
		gotoxy(0, i);
		printf("#");
		gotoxy(40, i);
		printf("#");
	}

}

void Add_Random_Apple()
{
	gotoxy(rand() % 40, rand() % 20);
	printf("@");
}

void Output_Snake()
{

}

int main()
{
	Snake* snake = (Snake*)malloc(sizeof(Snake));
	snake->next = NULL;
	snake->x = 1;
	snake->y = 1;
	char ch = 'm';

	create_game_field();

	while (1)
	{
		if (_kbhit())
			ch = _getch();

		switch (ch)
		{
			case 'w': 
			{

			}
			case 'a':
			{

			}
			case 's':
			{

			}
			case 'd':
			{

			}
		}

		if (snake->x >= 40 || snake->x <= 0 || snake->y <= 0 || snake->y >= 20)
		{
			system("cls");
			printf("Game Over\n");
			break;
		}

	}
	

	system("pause");
	return 0;
}
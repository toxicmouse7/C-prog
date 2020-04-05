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

typedef struct
{
	int x;
	int y;
} Apple;

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

void Add_Random_Apple(Apple* apple)
{
	apple->x = rand() % 40;
	apple->y = rand() % 20;
	if (apple->x == 0)
		apple->x++;
	if (apple->y == 0)
		apple->y++;
}

void Output_Apple(Apple* apple)
{
	gotoxy(apple->x, apple->y);
	printf("@");
}

void Output_Snake(Snake* snake)
{
	while (snake != NULL)
	{
		gotoxy(snake->x, snake->y);
		printf("*");
		snake = snake->next;
	}
}

void Remove_Old_Snake(Snake* snake)
{
	while (snake != NULL)
	{
		gotoxy(snake->x, snake->y);
		printf(" ");
		snake = snake->next;
	}
}

void increase_snake(Snake* snake, char ch)
{
	Snake* tmp;
	while (snake->next != NULL)
		snake = snake->next;
	tmp = snake;
	snake->next = (Snake*)malloc(sizeof(Snake));
	snake = snake->next;
	snake->next = NULL;
	snake->previous = tmp;
	if (ch == 'w')
	{
		snake->y = tmp->y + 1;
		snake->x = tmp->x;
	}
	else if (ch == 'a')
	{
		snake->y = tmp->y;
		snake->x = tmp->x + 1;
	}
	else if (ch == 's')
	{
		snake->y = tmp->y - 1;
		snake->x = tmp->x;
	}
	else if (ch == 'd')
	{
		snake->y = tmp->y;
		snake->x = tmp->x - 1;
	}
}

int main()
{
	Snake* snake = (Snake*)malloc(sizeof(Snake));
	Snake* snake_go;
	Snake* tmp;
	Apple* apple = (Apple*)malloc(sizeof(Apple));
	int score = 0;
	snake->next = NULL;
	snake->previous = NULL;
	snake->x = 20;
	snake->y = 10;
	char ch = 'm';

	create_game_field();
	Add_Random_Apple(apple);
	Output_Apple(apple);

	while (1)
	{
		if (_kbhit())
			ch = _getch();

		switch (ch)
		{
			case 'w': 
			{
				Remove_Old_Snake(snake);
				snake_go = snake;
				while (snake_go->next != NULL)
					snake_go = snake_go->next;
				while (snake_go->previous != NULL)
				{
					tmp = snake_go->previous;
					snake_go->y = tmp->y;
					snake_go = snake_go->previous;
				}
				
				/*snake_go = snake;
				while (snake_go != NULL)
				{
					snake_go->y--;
					snake_go = snake_go->next;

				}*/
				Output_Snake(snake);
				Sleep(300);
				break;
			}
			case 'a':
			{
				Remove_Old_Snake(snake);
				snake_go = snake;
				while (snake_go != NULL)
				{
					snake_go->x--;
					snake_go = snake_go->next;

				}
				Output_Snake(snake);
				Sleep(300);
				break;
			}
			case 's':
			{
				Remove_Old_Snake(snake);
				snake_go = snake;
				while (snake_go != NULL)
				{
					snake_go->y++;
					snake_go = snake_go->next;

				}
				Output_Snake(snake);
				Sleep(300);
				break;
			}
			case 'd':
			{
				Remove_Old_Snake(snake);
				snake_go = snake;
				while (snake_go != NULL)
				{
					snake_go->x++;
					snake_go = snake_go->next;

				}
				Output_Snake(snake);
				Sleep(300);
				break;
			}
		}

		if (snake->x >= 39 || snake->x < 1 || snake->y < 1 || snake->y >= 19)
		{
			system("cls");
			printf("Game Over\n");
			break;
		}

		if (snake->x == apple->x && snake->y == apple->y)
		{
			increase_snake(snake, ch);
			Add_Random_Apple(apple);
			Output_Apple(apple);
			score++;
		}

	}
	

	system("pause");
	return 0;
}
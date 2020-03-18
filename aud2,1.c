#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

typedef struct
{
	char* string;
	struct List* next;
	struct List* previous;
} List;

void Free19(List* list)
{
	while (list->next != 0)
		list = list->next;
	for (int i = 0; i < 19; i++)
	{
		list = list->previous;
		free(list->next);
	}
	list->next = NULL;
}

void AddRandomString(List* list)
{
	List* temp;
	while (list->next != NULL)
		list = list->next;

	list->next = (List*)malloc(sizeof(List));
	temp = list;
	list = list->next;
	list->previous = temp;
	list->next = NULL;
	list->string = (char*)calloc(15, sizeof(char));
	for (int i = 0; i < 15; i++)
	{
		list->string[i] = rand() % 128;
		if (list->string[i] < 32 || list->string[i] == 57 || list->string[i] == 127)
			list->string[i] == ' ';
	}
	list->string[14] = '\0';
}

void OutputString(List* list, int i)
{
	for (int j = 0; j < i; j++)
	{
		list = list->next;
	}
	printf("%s", list->string);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	char nullstr[20] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	int k = 0, y = 19, count = 1, flag = 0;
	List* str = (List*)malloc(sizeof(List)), *temp;
	str->next = 0;
	str->previous = 0;
	str->string = (char*)calloc(15, sizeof(char));
	for (int i = 0; i < 15; i++)
	{
		str->string[i] = rand() % 256;
		if (str->string[i] == 7)
			str->string[i] == ' ';
	}
	str->string[14] = '\0';

	system("color 02");
	while (1)
	{
		for (int y1 = y, k1 = k; k1 < count; k1++, y1++)
		{
			gotoxy(0, y1);
			//if (flag == 0)
			//{
				OutputString(str, k1);
			//}
			//else
			//{
				
				//flag = 0;
			//}
		}
		if (count != 40)
			AddRandomString(str);
		else
		{
			Free19(str);
			count = 20;
			k = 0;
			//y = 19;
		}
		Sleep(300);
		system("cls");
		if (count < 20)
		{
			if (y != 0)
				y--;
			count++;
		}
		else
		{
			//gotoxy(0, 0);
			//printf("%s", nullstr);
			count++;
			k++;
		}
	}

	system("pause");
	return 0;
}
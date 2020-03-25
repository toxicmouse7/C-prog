#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main()
{
	char* pass, nullstr[3] = {' ', ' ', '\0'};
	pass = (char*)malloc(21 * sizeof(char));
	pass[20] = '\0';

	printf("Write your password(Max 20 symbols):\n");

	for (int i = 0; i < 20; i++)
	{
		pass[i] = _getch();
		if (pass[i] != '\r')
			printf("*");

		if (pass[i] == '\b')
		{
			if (i >= 2)
			{
				i -= 2;
				gotoxy(i + 1, 1);
				printf("%s", nullstr);
				gotoxy(i + 1, 1);
			}
			else if (i == 1)
			{
				i = -1;
				gotoxy(0, 1);
				printf("%s", nullstr);
				gotoxy(0, 1);
			}
			else if (i == 0)
			{
				i = -1;
				gotoxy(0, 1);
				printf("%s", nullstr);
				gotoxy(0, 1);
			}
		}

		if (pass[i] == '\r')
		{
			pass[i] = '\0';
			if (i >= 1)
				if (pass[i - 1] == '\b')
					pass[i - 1] = '\0';
			break;
		}
	}

	system("pause");
	return 0;
}
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

int passcheck(char* pass)
{
	int ch = 0, val = 0;
	if (strlen(pass) <= 6)
		return 0;
	for (int i = 0; i < strlen(pass); i++)
	{
		if (i + 2 < strlen(pass))
		{
			if (pass[i] == pass[i + 1] && pass[i + 1] == pass[i + 2])
				return 0;
			if (pass[i] > 47 && pass[i] < 58)
			{
				if ((pass[i + 2] - pass[i + 1] == 1) && (pass[i + 1] - pass[i] == 1))
					return 0;
				if ((pass[i] - pass[i + 1] == 1) && (pass[i + 1] - pass[i + 2] == 1))
					return 0;
			}
		}
		if (pass[i] > 47 && pass[i] < 58)
			val++;
		if ((pass[i] > 64 && pass[i] < 91) || (pass[i] > 96 && pass[i] < 123))
			ch++;
		else if ((pass[i] < 65 && pass[i] > 90) && (pass[i] < 97 && pass[i] > 122) && (pass[i] < 48 && pass[i] > 57))
			return 0;
	}

	if (val < 3 && ch < 3)
		return 0;

	return 1;
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

	if (passcheck(pass) == 1)
		printf("\nGood password!\n");
	else printf("\nBad password :C\n");

	system("pause");
	return 0;
}
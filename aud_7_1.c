#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nullascii(int* mass)
{
	for (int i = 0; i < 255; i++)
		mass[i] = 0;
}

int main()
{
	int i = 0, lenght = 0, maxlenght = 0, sure_k;
	int ascii[255] = { 0 };
	char* string = (char*)calloc(1, sizeof(char)), check;
	
	while (1)
	{
		string[i] = _getche();
		if (string[i] == '\r')
		{
			string[i] = '\0';
			break;
		}
		if (string[i] == '\b')
		{
			if (i > 1)
			{
				i -= 1;
				string[i] = '\0';
				system("cls");
				printf("%s", string);
				continue;
			}
			if (i <= 1)
			{
				i = 0;
				system("cls");
				string = (char*)realloc(string, i + 1);
				continue;
			}
		}

		i++;
		string = (char*)realloc(string, i + 1);
	}
	string[i] = '\0';
	system("cls");
	i = 0;

	char* ans = (char*)calloc(strlen(string), sizeof(char));

	for (int j = 0; j < strlen(string); j++)
	{
		int k = 0;
		while (ascii[(int)string[k + j]] != 1 && k + j < strlen(string))
		{
			ascii[(int)string[k + j]]++;
			lenght++;
			k++;
		}
		if (lenght > maxlenght)
		{
			maxlenght = lenght;
			lenght = 0;
			sure_k = j;
		}
		else lenght = 0;
		nullascii(ascii);
	}

	for (int q = 0; q < maxlenght; q++)
	{
		ans[q] = string[sure_k + q];
	}

	printf("%s\nLenght: %d\n", ans, maxlenght);

	free(string);
	return 0;
}
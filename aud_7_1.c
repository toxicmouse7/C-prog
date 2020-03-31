#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i = 0, lenght = 0;
	int ascii[255] = { 0 };
	char* string = (char*)calloc(1, sizeof(char));
	
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

	for (int j = 0; j < strlen(string); j++)
	{
		if (ascii[(int)string[j]] == 0)
		{
			printf("%c", string[j]);
			ascii[(int)string[j]] = 1;
			lenght++;
		}
	}

	printf("\n%s\nLenght of substring: %d\n", string, lenght);

	free(string);
	return 0;
}
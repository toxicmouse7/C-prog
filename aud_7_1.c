#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i = 0;
	char ascii[255];
	char* string = (char*)calloc(1, sizeof(char));
	
	while (1)
	{
		string[i] = _getche();
		if (string[i] == '\r')
		{
			string[i] = '\0';
			break;
		}

		i++;
		string = (char*)realloc(string, i + 1);
	}

	system("cls");
	printf("%s\n", string);

	return 0;
}
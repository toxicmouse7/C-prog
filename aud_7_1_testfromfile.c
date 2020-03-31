#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* f;
	errno_t err;
	int i = 0, lenght = 0;
	int ascii[255] = { 0 };
	char* string = (char*)calloc(1, sizeof(char));
	
	err = fopen_s(&f, "string.txt", "r");
	if (err != 0)
		return err;
	
	while (!feof(f))
	{
		fscanf_s(f, "%c", &string[i], (unsigned)_countof(string));
		i++;
		string = (char*)realloc(string, i + 1);
	}
	string[i-1] = '\0';
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
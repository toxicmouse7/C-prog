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
	FILE* f;
	errno_t err;
	int i = 0, lenght = 0, maxlenght = 0, sure_k;
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
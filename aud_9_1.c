#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock.h>
#include <locale.h>
#include <time.h>
#define INFO_BUFFER_SIZE 50


int main()
{
	setlocale(LC_ALL, "Russian");
	TCHAR infoBuf[INFO_BUFFER_SIZE];
	DWORD bufCharCount = INFO_BUFFER_SIZE;
	struct tm time_date;
	time_t long_time = time(NULL);
	char timebuf[26];

	GetUserName(infoBuf, &bufCharCount);
	wprintf(L"Имя пользователя: %s\n", infoBuf);
	bufCharCount = INFO_BUFFER_SIZE;

	GetComputerName(infoBuf, &bufCharCount);
	wprintf(L"Имя компьютера: %s\n", infoBuf);
	bufCharCount = INFO_BUFFER_SIZE;

	localtime_s(&time_date, &long_time);
	asctime_s(timebuf, 26, &time_date);
	printf("Время и дата: %s", timebuf);

	GetWindowsDirectory(infoBuf, INFO_BUFFER_SIZE);
	wprintf(L"Директория Windows: %s\n", infoBuf);
	bufCharCount = INFO_BUFFER_SIZE;

	system("pause");
	return 0;
}
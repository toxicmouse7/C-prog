#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock.h>
#include <locale.h>
#include <time.h>
#define INFO_BUFFER_SIZE 50

void wday(struct tm time_date)
{
	if (time_date.tm_wday == 0)
		printf("Понедельник\n");
	else if (time_date.tm_wday == 1)
		printf("Вторник\n");
	else if (time_date.tm_wday == 2)
		printf("Среда\n");
	else if (time_date.tm_wday == 3)
		printf("Четверг\n");
	else if (time_date.tm_wday == 4)
		printf("Пятница\n");
	else if (time_date.tm_wday == 5)
		printf("Суббота\n");
	else if (time_date.tm_wday == 6)
		printf("Воскресение\n");
}

void month(struct tm time_date)
{
	if (time_date.tm_mon == 0)
		printf("Января");
	else if (time_date.tm_mon == 1)
		printf("Февраля");
	else if (time_date.tm_mon == 2)
		printf("Марта");
	else if (time_date.tm_mon == 3)
		printf("Апреля");
	else if (time_date.tm_mon == 4)
		printf("Мая");
	else if (time_date.tm_mon == 5)
		printf("Июня");
	else if (time_date.tm_mon == 6)
		printf("Июля");
	else if (time_date.tm_mon == 7)
		printf("Августа");
	else if (time_date.tm_mon == 8)
		printf("Сентября");
	else if (time_date.tm_mon == 9)
		printf("Октября");
	else if (time_date.tm_mon == 10)
		printf("Ноября");
	else if (time_date.tm_mon == 11)
		printf("Декабря");
}


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
	printf("Время: %d:%d:%d\n", time_date.tm_hour, time_date.tm_min, time_date.tm_sec);
	printf("Дата: %d ", time_date.tm_mday);
	month(time_date);
	printf(" %d, ", time_date.tm_year + 1900);
	wday(time_date);
	

	GetWindowsDirectory(infoBuf, INFO_BUFFER_SIZE);
	wprintf(L"Директория Windows: %s\n", infoBuf);
	bufCharCount = INFO_BUFFER_SIZE;

	system("pause");
	return 0;
}
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
		printf("�����������\n");
	else if (time_date.tm_wday == 1)
		printf("�������\n");
	else if (time_date.tm_wday == 2)
		printf("�����\n");
	else if (time_date.tm_wday == 3)
		printf("�������\n");
	else if (time_date.tm_wday == 4)
		printf("�������\n");
	else if (time_date.tm_wday == 5)
		printf("�������\n");
	else if (time_date.tm_wday == 6)
		printf("�����������\n");
}

void month(struct tm time_date)
{
	if (time_date.tm_mon == 0)
		printf("������");
	else if (time_date.tm_mon == 1)
		printf("�������");
	else if (time_date.tm_mon == 2)
		printf("�����");
	else if (time_date.tm_mon == 3)
		printf("������");
	else if (time_date.tm_mon == 4)
		printf("���");
	else if (time_date.tm_mon == 5)
		printf("����");
	else if (time_date.tm_mon == 6)
		printf("����");
	else if (time_date.tm_mon == 7)
		printf("�������");
	else if (time_date.tm_mon == 8)
		printf("��������");
	else if (time_date.tm_mon == 9)
		printf("�������");
	else if (time_date.tm_mon == 10)
		printf("������");
	else if (time_date.tm_mon == 11)
		printf("�������");
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
	wprintf(L"��� ������������: %s\n", infoBuf);
	bufCharCount = INFO_BUFFER_SIZE;

	GetComputerName(infoBuf, &bufCharCount);
	wprintf(L"��� ����������: %s\n", infoBuf);
	bufCharCount = INFO_BUFFER_SIZE;

	localtime_s(&time_date, &long_time);
	printf("�����: %d:%d:%d\n", time_date.tm_hour, time_date.tm_min, time_date.tm_sec);
	printf("����: %d ", time_date.tm_mday);
	month(time_date);
	printf(" %d, ", time_date.tm_year + 1900);
	wday(time_date);
	

	GetWindowsDirectory(infoBuf, INFO_BUFFER_SIZE);
	wprintf(L"���������� Windows: %s\n", infoBuf);
	bufCharCount = INFO_BUFFER_SIZE;

	system("pause");
	return 0;
}
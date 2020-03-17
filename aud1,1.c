#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	double value_;
	struct List* next;
	struct List* previous;
} List;

void AddRandomValue(List* list)
{
	while (list->next != NULL)
		list = list->next;

	list->next = (List*)malloc(sizeof(List));
	list = list->next;
	list->next = NULL;
	list->value_ = rand() % 100;

}

void AddBeforeValue(List* list, double myvalue)
{
	List* prev, *pt = NULL;
	int flag = 0, count = 0;
	while (list->value_ != myvalue)
	{
		if (list->next != NULL)
		{
			prev = list;
			list = list->next;
			list->previous = prev;
			count++;
		}
		else
		{
			time_t time_start1 = time(NULL), time_end1 = time(NULL);
			printf("There is no value you typed\n");
			while (time_end1 - time_start1 != 3)
				time_end1 = time(NULL);
			flag = 1;
			break;
		}
	}
	if (count == 0)
	{
		time_t time_start = time(NULL), time_end = time(NULL);
		printf("Can't add an element before the first\n");
		while (time_end - time_start != 3)
			time_end = time(NULL);
		return NULL;
	}
		if (flag == 0)
	{
		list = list->previous;
		pt = list->next;
		list->next = (List*)malloc(sizeof(List));
		list = list->next;
		list->value_ = rand();
		list->next = pt;
	}
}

void OutputList(List* list)
{
	while (list != NULL)
	{
		printf("%.0lf -> ", list->value_);
		list = list->next;
	}
}

int main()
{
	char ch;
	int cls;
	double myvalue;
	List* list = (List*)malloc(sizeof(List));
	list->value_ = rand() % 100;
	list->next = NULL;

	start:
	printf("1. Add an element into list\n2. Add an element before the element you want\n3. Output list\n4. Exit\n");
	ch = _getche();
	switch (ch)
	{
		default: return 1;
		case '1':
		{
			AddRandomValue(list);
			system("cls");
			goto start;
			break;
		}
		case '2':
		{
			printf("\nType value: ");
			scanf_s("%lf", &myvalue);
			AddBeforeValue(list, myvalue);
			system("cls");
			goto start;
			break;
		}
		case '3': 
		{
			system("cls");
			OutputList(list);
			printf("\nClear the screen?\n1. Yes\n");
			scanf_s("%d", &cls);
			if (cls == 1)
				system("cls");
			goto start;
		}
	}

	system("pause");
	return 0;
}
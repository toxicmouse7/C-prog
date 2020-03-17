#include <stdio.h>
#include <stdlib.h>

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
	int flag = 0;
	while (list->value_ != myvalue)
	{
		if (list->next != NULL)
		{
			prev = list;
			list = list->next;
			list->previous = prev;
		}
		else
		{
			printf("There is no value you typed\n");
			flag = 1;
			break;
		}
		if (flag == 0)
		{
			list = list->previous;
			pt = list->next;
			list->next = (List*)malloc(sizeof(List));
			list = list->next;
			list->next = pt;
		}
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
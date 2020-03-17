#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	double value_;
	struct List* next;
} List;

void AddRandomValue(List* list)
{
	while (list->next != NULL)
		list = list->next;

	list->next = (List*)malloc(sizeof(List));
	list = list->next;
	list->value_ = rand();

}

void AddBeforeValue(List* list, double myvalue)
{
	List* ptr, *ptr1;
	while (list->value_ != myvalue)
	{
		if (list->next != NULL)
		{
			ptr = list;
			list = list->next;
		}
		else
		{
			printf("There is no value you typed\n");
			break;
		}
		ptr->next = (List*)malloc(sizeof(List));
		ptr = ptr->next;
		ptr->next = ptr1;
	}
}

void OutputList(List* list)
{
	while (list != NULL)
	{
		printf("%lf -> ", list->value_);
		list = list->next;
	}
}

int main()
{
	char ch;
	int cls;
	double myvalue;
	List* list = (List*)malloc(sizeof(List));
	list->value_ = rand();
	void (*func) (List* list);

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
			scanf_s("%d", cls);
			if (cls == 1)
				system("cls");
			goto start;
		}
	}

	system("pause");
	return 0;
}
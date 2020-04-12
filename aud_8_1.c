#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct List
{
	double value;
	struct List* next;
	struct List* previous;
};

typedef struct List list;

void outputToRight(list* head)
{
	while (head != NULL)
	{
		if (head->next != NULL)
			printf("%.1lf -> ", head->value);
		else if (head->next == NULL)
			printf("%.1lf.\n", head->value);
		head = head->next;
	}
}

void outputToLeft(list* tail)
{
	while (tail != NULL)
	{
		if (tail->previous != NULL)
			printf("%.1lf -> ", tail->value);
		else if (tail->previous == NULL)
			printf("%.1lf.\n", tail->value);
		tail = tail->previous;
	}
}

list* addToRight(list* tail)
{
	tail->next = (list*)malloc(sizeof(list));
	tail->next->previous = tail;
	tail = tail->next;
	tail->value = rand() % 100;
	tail->next = NULL;

	return tail;
}

list* addToLeft(list* head)
{
	head->previous = (list*)malloc(sizeof(list));
	head->previous->next = head;
	head = head->previous;
	head->previous = NULL;
	head->value = rand() % 100;

	return head;
}

list* findByValue(list* head, double _value)
{
	while (head != NULL)
	{
		if (head->value == _value)
		{
			return head;
		}
		head = head->next;
	}

	return NULL;
}

void swapTwoElements(list* head)
{
	double value1, value2, temp;
	list* cur, * cur1;
	printf("Введите значения элементов, которые нужно поменять (source & destination): ");
	scanf_s("%lf%lf", value1, value2);
	cur = findByValue(head, value1);
	cur1 = findByValue(head, value2);
	if (cur == NULL || cur1 == NULL)
	{
		printf("Элементов с такими значениями не обнаружено\n");
		return (void*)NULL;
	}
	cur->value = value2;
	cur1->value = value1;
}

void deleteByValue(list* head, double _value)
{
	list* cur = findByValue(head, _value);
	if (cur == NULL)
	{
		printf("Элемент по указанному значению не найден\n");
		return NULL;
	}
	else
	{
		cur->previous->next = cur->next;
		cur->next->previous = cur->previous;
		printf("Значение по адресу %p со значением %lf удалено\n", cur, cur->value);
		free(cur);
	}
}

void addBeforeCurrent(list* current)
{
	if (current == NULL)
	{
		printf("Текущий элемент не выбран\n");
		return NULL;
	}
	list* new = (list*)malloc(sizeof(list));
	list* temp;
	new->value = rand() % 100;
	temp = current->previous;
	current->previous = new;
	new->previous = temp;
	new->next = current;
	temp->next = new;
	printf("Элемент добавлен успешно\n");
}
void addBeforeValue(list* head, list* current)
{
	double value;
	scanf_s("%lf", &value);
	current = findByValue(head, value);
	addBeforeCurrent(current);
}

//void deleteByPointer(list* current)
//{
//	scanf_s("%p", current);
//	current->previous->next = current->next;
//	current->next->previous = current->previous;
//	free(current);
//	current = NULL;
//}

void freeAll(list* head, list* tail)
{
	while (head->next != NULL)
	{
		head = head->next;
		free(head->previous);
	}
	free(tail);
}

void splice(list* left, list* right, list* position)
{
	left->previous->next = right->next;
	left->previous = position;
	right->next = position->next;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	list* head = (list*)malloc(sizeof(list));
	list* tail = (list*)malloc(sizeof(list));
	list* current = NULL;
	head->next = tail;
	head->previous = NULL;
	tail->next = NULL;
	tail->previous = head;
	head->value = rand() % 100;
	tail->value = rand() % 100;

	while (1)
	{
		char ch;

		printf("1.Вывести из начала в конец\n2.Вывести из конца в начало\n3.Добавить элемент в конец\n4.Добавить элемент в начало\n5.Найти элемент по значению\n6.Удалить элемент по значению\n7.Добавить элемент перед текущим\n8.Добавить перед значением\n");
		ch = _getch();
		system("cls");

		switch (ch)
		{
		case '1':
		{
			outputToRight(head);
			break;
		}
		case '2':
		{
			outputToLeft(tail);
			break;
		}
		case '3':
		{
			tail = addToRight(tail);
			break;
		}
		case '4':
		{
			head = addToLeft(head);
			break;
		}
		case '5':
		{
			double value;
			printf("Введите число: ");
			scanf_s("%lf", &value);
			printf("\n");
			current = findByValue(head, value);
			if (current == NULL)
				printf("Элемент не найден\n");
			else printf("%p - адрес элемента\n", current);
			break;
		}
		case '6':
		{
			double value;
			printf("Введите число: ");
			scanf_s("%lf", &value);
			printf("\n");
			deleteByValue(head, value);
		}
		case '7':
		{
			addBeforeCurrent(current);
			break;
		}
		case '8': 
		{
			addBeforeValue(head, current);
			break;
		}
		//case '9':
		//{
		//	deleteByPointer(current);
		//	break;
		//}
		default: 
		{
			freeAll(head, tail);
			exit(3);
		}
		}
	}

	freeAll(head, tail);
	system("pause");
	return 0;
}
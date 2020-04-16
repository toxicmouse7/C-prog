#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define compare pow(10, -3)

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
			printf("%.4lf -> ", head->value);
		else if (head->next == NULL)
			printf("%.4lf.\n", head->value);
		head = head->next;
	}
}

void outputToLeft(list* tail)
{
	while (tail != NULL)
	{
		if (tail->previous != NULL)
			printf("%.3lf -> ", tail->value);
		else if (tail->previous == NULL)
			printf("%.3lf.\n", tail->value);
		tail = tail->previous;
	}
}

list* addToRight(list* tail)
{
	int minus = rand()%3 + 1;
	tail->next = (list*)malloc(sizeof(list));
	tail->next->previous = tail;
	tail = tail->next;
	tail->value = (double)(rand()) / RAND_MAX * 100;
	if (minus == 2)
		tail->value *= -1;
	tail->next = NULL;

	return tail;
}

list* addToLeft(list* head)
{
	int minus = rand() % 3 + 1;
	head->previous = (list*)malloc(sizeof(list));
	head->previous->next = head;
	head = head->previous;
	head->previous = NULL;
	head->value = (double)(rand()) / RAND_MAX * 100;
	if (minus == 2)
		head->value *= -1;

	return head;
}

list* findByValue(list* head, double _value)
{
	while (head != NULL)
	{
		if (fabs(head->value - _value) < compare)
		{
			return head;
		}
		head = head->next;
	}

	return NULL;
}

void swapTwoElements(list* head)
{
	double value1, value2;
	list* cur, * cur1, *temp = (list*)malloc(sizeof(list));
	printf("Введите значения элементов, которые нужно поменять (source & destination): ");
	scanf_s("%lf%lf", &value1, &value2);
	cur = findByValue(head, value1);
	cur1 = findByValue(head, value2);
	if (cur == NULL || cur1 == NULL)
	{
		printf("Элементов с такими значениями не обнаружено\n");
		return (void*)NULL;
	}
	//if (cur1->next != cur || cur1->previous != cur)
	//{
		//if (cur1->next != NULL)
			temp->next = cur1->next;
		//else temp->next = NULL;
		//if (cur1->previous != NULL)
			temp->previous = cur1->previous;
		//else temp->previous = NULL;
		if (cur->previous != NULL)
			cur->previous->next = cur1;
		if (cur->next != NULL)
			cur->next->previous = cur1;
		if (cur1->next != NULL)
			cur1->next->previous = cur;
		if (cur1->previous != NULL)
			cur1->previous->next = cur;
		//if (cur1->next != NULL)
			cur1->next = cur->next;
		//if (cur1->previous != NULL)
			cur1->previous = cur->previous;
		//if (cur->previous != NULL && temp->previous != NULL)
			cur->previous = temp->previous;
		//if (cur->next != NULL && temp->next != NULL)
			cur->next = temp->next;
	//}
	/*else
	{
		temp->next = cur1->next;
		temp->previous = cur1->previous;
		cur1->next = cur->next;
		cur1->previous = cur->previous;
	}*/
	free(temp);
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
	if (position->next == left)
		return NULL;

	if (left->previous != NULL)
		left->previous->next = right->next;
	if (right->next != NULL)
		right->next->previous = left->previous;
	if (left->previous != NULL)
		left->previous = position;
	if (right->next != NULL)
		right->next = position->next;
	position->next->previous = right;
	position->next = left;
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
	head->value = (double)(rand()) / RAND_MAX * 100;
	tail->value = (double)(rand()) / RAND_MAX * 100;
	list* right, * left;

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
		case '9':
		{
			/*double value;
			scanf_s("%lf", &value);
			left = findByValue(head, value);
			scanf_s("%lf", &value);
			right = findByValue(head, value);
			splice(left, right, current);
			break;*/
			swapTwoElements(head);
			break;
		}
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
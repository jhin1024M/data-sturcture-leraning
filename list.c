#include<stdio.h>
#include<stdlib.h>
typedef struct _node
{
	int value;
	struct _node* next;
}Node;
typedef struct _list {
	Node* head;
	Node* tail;
}list;
void add(int,list *);
void print(list *);
void search(list*,int);
int main()
{	
	list list;
	list. head = NULL;
	list. tail = NULL;
	int number;
	do {
		scanf_s("%d", &number);
		add(number, &list);
	} while (number != -1);
	int a;
	printf("intput your number");
	scanf_s("%d", &a);
	search(&list, a);
	print(&list);
	return 0;
}
void add(int number, list* list)
{
	if (number != -1)
	{
		Node* p = (Node*)malloc(sizeof(Node));
		p->value = number;
		p->next = NULL;

		if (list->head)
		{
			list->tail->next = p;
			list->tail = p;

		}
		else {
			list->head = p;  list->tail = p;
		}
	}
}
void print(list* list)
{
	for (Node* a = list->head; a; a = a->next)
	{
		printf("%4d", a->value);
	}
}
void search(list* list, int a)
{
	Node* q = NULL; Node* p;
	int c = 1;
	for (p = list->head; p; )
	{
		c = 1;
		if (a == p->value)
		{
			
			if (!q)
			{
				list->head = list->head->next;
				free(p);
				p = list->head;
				c = 0;
			}
			
			
			else {
				q->next = p->next;
				free(p);
				p = q->next;
				c = 0;
			}
		}
		if (c)
		{
			q = p; p = p->next;
		}
	}
}

int main()
{
	Node* p, *q;
	for (;p;)
	{
		q = p->next;
		free(p);
		p = q;
	}

}

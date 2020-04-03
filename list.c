#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node
{
	ElementType Data;
	Node* Next;
}Node;
typedef struct _list {
	Node* Head;
	Node* tail;
}List;
void Add(List* list, ElementType X);  //无表头情况  在表末添加
List* CreatList();
List* Deleted(List* list, ElementType X);
void Print(List* list);
void Free(List* list);
void Add(List* list, ElementType X)
{
	if (X != -1)
	{
		Node* p = (Node*)malloc(sizeof(Node));
		p->Data = X;
		p->Next = NULL;

		if (list->Head)			//先判断头空不空
		{
			list->tail->Next = p;
			list->tail = p;

		}
		else {
			list->Head = p;  list->tail = p;
		}
	}
}
List* CreatList()
{
	List* list;
	list = (List*)malloc(sizeof(List));
	list->Head = list->tail = NULL;
	ElementType X;
	while (X != -1)  //停止条件
	{
		scanf("%d", &X);
		Add(list, X);
	}
	return list;
}
List* Deleted(List* list, ElementType X)
{
	while (list->Head)  
	{
		if (list->Head->Data == X)				//删除条件
			list->Head = list->Head->Next;
	}
	Node* Tmp = list->Head;
	while (Tmp)
	{
		Node* t = Tmp->Next;
		while (t)
		{
			if (t->Data == X)
				t = t->Next;
		}
		Tmp = t;
	}
	return list;
}
void Print(List* list)
{
	Node* t = list->Head;
	while (t)
	{
		printf("%d", t->Data);
		t = t->Next;
	}
}
void Free(List* list)
{
	while (list->Head)
	{
		Node* t = list->Head->Next;
		free(list->Head);
		list->Head = t;
	}
	free(list);
}


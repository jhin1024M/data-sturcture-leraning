#pragma once     //采用n-1式环形数组队列  头是空的
#ifndef _QUEUE_
#define _QUEUE_
typedef struct QNode* Queue;
typedef enum {false,true} bool;
struct QNode
{
	ElementType* Data;
	int Maxsize;
	int Rear, Front;
};
Queue CreatQueue(int Maxsize);
bool AddQ(Queue, ElementType X);
ElementType DeleteQ(Queue);
//////////////////////////////////////////////////
Queue CreatQueue(int Maxsize)
{
	Queue Q = (Queue)malloc(sizeof(QNode));
	Q->Data = (ElementType*)malloc(sizeof(ElementType) * Maxsize);
	Q->Front = Q->Rear = 0;;
	Q->Maxsize = Maxsize;
}
bool AddQ(Queue Q, ElementType X)
{
	if ((Q->Rear + 1) % Q->Maxsize == Q->Front)
	{
		printf("Queue is FULL");
		return false;
	}
	else
	{
		Q->Rear = (Q->Rear + 1) % Q->Maxsize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}
ElementType DeleteQ(Queue Q)
{
	if (Q->Rear == Q->Front)
	{
		printf("Queue is EMPTY");
		return ERROR;
	}
	else
	{
		Q->Front = (Q->Front + 1) % Q->Maxsize;
		return Q->Data[Q->Front];
	}

}
#endif // !_QUEUE_


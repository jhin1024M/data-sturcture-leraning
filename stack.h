#pragma once
#ifndef _STACK_
#define _STACK_
typedef enum { true, false } bool;
typedef struct Node* stack;
struct Node
{
	ElementType* Data;
	int Top;
	int MaxSize;
};
stack CreatStack(int MaxSize);   
bool Push(stack S, ElementType X);
ElementType Pop(stack S);
stack CreatStack(int MaxSize)   //创建数组堆栈
{
	stack S;
	S = (stack)malloc(sizeof(struct Node));
	S->MaxSize = MaxSize;
	S->Top = -1;
	S->Data = (ElementType*)malloc(sizeof(ElementType) * MaxSize);
	return S;
}
bool Push(stack S, ElementType X)
{
	if (S->Top == S->MaxSize - 1)
	{
		printf("stack is full");
		return false;
	}
	else
		S->Data[++(S->Top)] = X;
	return false;
}
ElementType Pop(stack S)
{
	if (S->Top == -1)
	{
		printf("stack is empty");
		return -1;
	}
	else  return S->Data[(S->Top)--];
}
#endif // !_STACK_

#pragma once
#ifndef _LINK_H
#define _LINK_H
#include<stdio.h>
#include <stdlib.h>
#define ElementType  int
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
List Read();  //craet a new link
List Read()
{
    List head, tail,p;
    int a,i=0;
    head = tail = NULL;
    scanf_s("%d", &a);
    for (i; i < a; i++)
    {   
        
        p = (List)malloc(sizeof(Node));
        scanf_s("%d", &p->Data);
        p->Next = NULL;
        if (head)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->Next = p;
            p = tail;
        }
    }

    return head;
}
void Print(); // print the link
void Print(List L)
{
    while (L)
    {
        printf("%d", L->Data);
        L = L->Next;
    }
}
List Reverse(List L);
List Reverse(List L)
{
    List p,a,t;
    a = L;
    p = a->Next;
    a->Next = NULL;
    while (p)
    {
        t = p->Next;
        p->Next = a;
        a = p;
        p = t;
    }
   
    return a;
}
#endif // !_LINK_H

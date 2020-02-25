#include<stdio.h>
#include<stdlib.h>
//用两个链表来求和
typedef struct Node* link;
struct Node 
{
	int coef, expon;
	link link;
};
link PUT(int );
link Add(link, link);
int compare(int, int);
void attach(int, int, link*);
void print(link);
link Mult(link, link);
int main()
{
	//读入
	int N;
	link p1, p2,p3,p4;
	scanf_s("%d", &N);
	p1=PUT(N);
	scanf_s("%d", &N);
	p2=PUT(N);
	//相加
	p3 = Add(p1, p2);
	//相乘
	p4 = Mult(p1, p2);
	//输出
	print(p4);
	printf("\n");
	print(p3);
	return 0;
}
link PUT(int N)
{
	link head, tail;
	head = tail = NULL;
	while (N--)
	{
		link p;
		p = (link)malloc(sizeof(struct Node));
		scanf_s("%d", &p->coef);
		scanf_s("%d", &p->expon);
		p->link = NULL;
		if (!head) 
			head = tail = p;
		else
		{
			tail->link = p;
			tail = p;
		}
	}
	return head;
}
int compare(int a, int b)
{
	if (a > b)  return 1;
	else if (a < b)  return -1;
	else if (a == b)  return 0;
}
void attach(int a, int b, link*rear)
{
	link p = (link)malloc(sizeof(struct Node));
	p->coef = a;
	p->expon = b;
	p->link = NULL;
	(*rear)->link = p;
	(*rear) = p;
	
	
}
link Add(link p1, link p2)  //比较p1 p2所指的指数大小  处理后连接到p3
{
	link p3,rear;
	p3 = (link)malloc(sizeof(struct Node));
	rear = p3;
	int i = 0;
	//比较大小
	while (p1&&p2)
	{
		switch (compare(p1->expon, p2->expon))
		{
		case 1:attach(p1->coef, p1->expon, &rear);
			p1 = p1->link;
			break;
		case -1:
			attach(p2->coef, p2->expon, &rear);
			p2 = p2->link;
			break;
		case 0:
			if (p1->coef + p2->coef)
			{
				attach(p1->coef + p2->coef, p1->expon, &rear);
				p1 = p1->link;
				p2 = p2->link;
			}
			else
			{
				
				p1 = p1->link;
				p2 = p2->link;
			}
			break;
		}
	}
	if (p1)
	{
		while (p1)
		{
			attach(p1->coef, p1->expon, &rear);
			p1 = p1->link;
		}
	}
	else while (p2)
	{
		attach(p2->coef, p2->expon, &rear);
		p2 = p2->link;
	}
	while (i--)
	{
		attach(0, 0, &rear);
	}
	rear = p3->link;
	free(p3);
	return rear;
	
}
void print(link p)
{
	int a = 0;
	while (p)
	{
		if (a) printf(" ");
		printf("%d %d", p->coef, p->expon);
		a = 1;
		p = p->link;
	}
}
/*link Mult(link p1, link p2)
{
	link p3, p4,rear,t,a;
	p4 = NULL;
	int i ,j;
	
	while (p1)
	{
		rear = (link)malloc(sizeof(struct Node));
		p3 = rear;
		a = p2;
		while (a)
		{
			i = p1->coef * a->coef;
			if (i) j = p1->expon + a->expon;
			else j = 0;
			attach(i, j, &rear);
			
			a = a->link;
		}
		
		t = p3;
		p3 = p3->link;
		free(t);
		p4 = Add(p3, p4);
		p1 = p1->link;
	}
	return p4;
}*/
link Mult(link p1, link p2)
{
	link p3,rear,t;
	p3 = (link)malloc(sizeof(struct Node));
	p3->link = NULL;
	t = p2;
	while (p1)
	{
		p2 = t;
		while (p2)
		{
			rear = p3;
			link p = (link)malloc(sizeof(struct Node));
			p->coef = p1->coef * p2->coef;
			p->expon = p1->expon + p2->expon;
			p->link = NULL;
			if (!rear->link)  rear->link = p;
			else
			{
				while ( rear->link&&rear->link->expon > p->expon)
				{
					rear = rear->link;
				}
				if (rear->link&&rear->link->expon == p->expon)
				{
					if (p->coef + rear->link->coef)
					{
						rear->link->coef += p->coef;
						free(p);
					}
					else
					{
						rear->link = rear->link->link;
						free(p);
					}

				}
				else
				{
						p->link = rear->link;
					rear->link = p;
				}
			}
			p2 = p2->link;
		}
		p1 = p1->link;
	}
	t = p3;
	p3 = p3->link;
	free(t);
	return p3;
}

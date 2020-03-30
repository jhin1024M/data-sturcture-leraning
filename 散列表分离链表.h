#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum { true, false }bool;
typedef struct HashEle Cell;
typedef Cell* Position;
struct HashEle
{
	ElementType data;
	int cnt;
	Cell* next;
};
typedef struct  HashTable* HashTable;
struct  HashTable
{
	int TableSize;
	Cell* heads;
};
HashTable CreatHashTable(int N)
{
	HashTable H;
	H = (HashTable)malloc(sizeof(struct  HashTable));
	H->TableSize = NextPrime(N);
	H->heads = (Cell*)malloc(sizeof(struct HashEle) * H->TableSize);
	for (int i = 0; i < H->TableSize; i++) {
		H->heads[i].data[0] = '\0';
		H->heads[i].next = NULL;
	}
}
int NextPrime(int N)
{
	int i, p = (N % 2) ? N + 2 : N + 1;
	while (p < MAXTABLESIZE)
	{
		for (i = sqrt(p); i > 2; i--)
			if (p % i == 0) break;
		if (i == 2) p += 2;
	}
	return p;
}
Position Find(HashTable H, ElementType Key)
{
	Position P;
	int Pos;
	Pos = Hash(Key, H->TableSize);
	P = H->heads[Pos].next;
	while (P&&strcmp(P->data,Key))
	{
		P = P->next;
	}
	return P;
}
bool Insert(HashTable H, ElementType Key)
{
	Position P, NewCell;
	int Pos;
	P = Find(H, Key);
	if (!P)
	{
		NewCell = (Position)malloc(sizeof(Cell));
		strcpy(NewCell->data, Key);
		Pos= Hash(Key, H->TableSize);
		NewCell->next = H->heads[Pos].next;
		H->heads[Pos].next = NewCell;
		return true;
	}
	else
	{
		printf("关键词已存在");
		return false;
	}
}
void DestroyTable(HashTable H)
{
	int i;
	Cell* Tmp,*P;
	for (i = 0; i < H->Size; i++) {
		P = H->Cells[i].next;
		while (P)
		{
			Tmp = P;
			P = P->next;
			free(Tmp);
		}
	}
	free(H->Cells);
	free(H);
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXTABLESIZE 100000
typedef int Index;
typedef Index Position;
typedef int ElementType;
typedef struct HashEntry Cell;
typedef enum { Legitmate, Empty, Deleted } EntryType; //三种状态
typedef enum { true, false }bool;
struct HashEntry
{
	ElementType data;
	EntryType Info;
};
typedef struct TbNode* HashTable;
struct TbNode
{
	int TableSize;
	Cell* Cells;
};
HashTable CreateTable(int TableSize) //建立一个哈希表
{
	HashTable H;
	H = (HashTable)malloc(sizeof(struct TbNode));
	H->TableSize = NextPrime(H->TableSize);//取一个素数作为表长；
	H->Cells = (Cell*)malloc(sizeof(Cell) * H->TableSize);
	for (int i = 0; i < H->TableSize; i++)
		H->Cells[i].Info = Empty;
	return H;
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
Position Find(HashTable H, ElementType Key)  //查找key  
{
	Position CurrentPos, NewPos;
	int CNum = 0;//冲突次数
	NewPos = CurrentPos = Hash(Key, H->TableSize);
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].data != Key) //字符用strcmp
	{
		if (++CNum % 2)
		{
			NewPos = CurrentPos + (CNum + 1) * (CNum + 1) / 4;
			if (NewPos >= H->TableSize)
				NewPos = NewPos % H->TableSize;
		}
		else
		{
			NewPos = CurrentPos - CNum * CNum / 4;
			if (NewPos < 0)
				NewPos += H->TableSize;
		}
	}
	return NewPos;
}
bool Insert(HashTable H, ElementType Key)
{
	Position Pos = Find(H, Key);
	if (H->Cells[Pos].Info != Legitmate)
	{
		H->Cells[Pos].data = Key;
		H->Cells[Pos].Info = Legitmate;
		return true;
	}
	else {

		printf("键值已存在")；
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

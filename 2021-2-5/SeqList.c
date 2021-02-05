#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListCheckCapacity(SL *ps)
{
	assert(ps);
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType *)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
		if (ps->a == NULL)
		{
			printf("À©ÈÝÊ§°Ü\n");
			exit(-1);
		}
	}
}
void SeqListInit(SL *ps)
{
	//s.a = 0;
	//s.capacity = 0;
	//s.size = NULL;
	ps->a = (SLDataType *)malloc(sizeof(SLDataType)* 4);
	if (ps->a == NULL)
	{
		printf("ÉêÇëÄÚ´æÊ§°Ü\n");
		exit(-1);

	}
	ps->size = 0;
	ps->capacity = 4;
}

void SeqListPrint(SL *ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SL *ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(SL *ps)
{
	assert(ps);
	//ps->a[ps->size - 1] = 0;(²»ÐèÒª)
	ps->size--;
}
//SeqListErase(ps,ps->size-1);
void SeqListPushFront(SL *ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end+1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SL *ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}
//SeqListInsert(ps,0,x);
void SeqListInsert(SL *ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos<=ps->size&&pos>=0);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SL *ps, int pos)
{
	assert(ps);
	assert(pos<ps->size&&pos>=0);
	int start = pos;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start+1];
		++start;
	}
	ps->size--;
}
void SeqListDestory(SL *ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
int SeqListFind(SL *ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	while (i < ps->size)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
		++i;
	}
	return -1;
}
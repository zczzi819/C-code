#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

SListNode* BuySListNode(SLDataType x)
{
	SListNode* newNode = (SListNode *)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("ÉêÇë½ÚµãÊ§°Ü\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->Next = NULL;
	return newNode;
}
void SListPushFront(SListNode** pphead, SLDataType x)
{
	SListNode*newNode = BuySListNode(x);
	newNode->Next = *pphead;
	*pphead = newNode;
}
void SListPopFront(SListNode**pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else 
	{
		SListNode* next = (*pphead)->Next;
		free(*pphead);
		*pphead = next;
	}
}
void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->Next;
	}
	printf("NULL");
	printf("\n");
}
void SListPushBack(SListNode** pphead, SLDataType x)
{
	SListNode* newNode = BuySListNode(x);
	SListNode* tail = *pphead;
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		while (tail->Next != NULL)
		{
			tail = tail->Next;
		}
		 BuySListNode(x);
		 tail->Next = newNode;
		
	}
	
}
void SListPopBack(SListNode** pphead)
{
	
	
	if (*pphead==NULL)
	{
		return;
	}
	else if ((*pphead)->Next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{	
		SListNode *prev = NULL;
		SListNode *tail = *pphead;
		while (tail->Next != NULL)
		{
			prev = tail;
			tail = tail->Next;
		}
		free(tail);
		prev->Next = NULL;
	}
	
}
SListFind(SListNode* phead, SLDataType x)
{
	SListNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->Next;
	}
	return NULL;
}
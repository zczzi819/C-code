#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __SLIST_H__
#define __SLIST_H__
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* Next;
}SListNode;

void SListPushBack(SListNode** pphead,SLDataType x);
void SListPopBack(SListNode** pphead);
void SListPushFront(SListNode** phead, SLDataType x);
void SListPopFront(SListNode** phead);
 SListFind(SListNode* phead, SLDataType x);
void SListPrint(SListNode** phead);

#endif

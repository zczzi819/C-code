#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;


typedef struct SeqList
{
	SLDataType *a;
	SLDataType size;//有效数据的大小
	SLDataType capacity;//容量
}SL,SeqList;
void SeqListPrint(SL *ps);
void SeqListInit(SL *ps);
void SeqListDestory(SL *ps);
void SeqListCheckCapacity(SL *ps);
void SeqListPushBack(SL *ps,SLDataType x);
void SeqListPopBack(SL *ps);
void SeqListPushFront(SL *ps,SLDataType x);
void SeqListPopFront(SL *ps);
void SeqListInsert(SL *ps,int pos,SLDataType x);
void SeqListErase(SL *ps, int pos);
int SeqListFind(SL *ps, SLDataType x);
#endif

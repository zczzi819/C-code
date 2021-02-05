#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"


void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s,1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s,5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPushFront(&s,-1);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListDestory(&s);
}




int main()
{
	TestSeqList1();
	system("pause");
	return 0;
}
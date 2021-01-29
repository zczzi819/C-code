#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
int main()
{
	SListNode* pList=NULL;
	SListPushBack(&pList,1);
	SListPushBack(&pList,2);
	SListPushBack(&pList,3);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPrint(pList);
	//SListPopFront(&pList);
	//SListPopFront(&pList);
	//SListPrint(pList);
	SListNode* pos = SListFind(pList, 1);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(pList);
	system("pause");
	return 0;
}
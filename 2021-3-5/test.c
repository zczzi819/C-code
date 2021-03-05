#include"Heap.h"

void HeapSort(int* a1, int n)
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	// 1.����
	//for (int i = n - 1; i >= 0; ++i)
	// ʱ�临�Ӷȣ�
	// ��������N���ڵ㣬���߶ȣ�logN
	// Ҫע������ʱ�临�ӶȲ���N*logN������ʱ�临�Ӷ���O(N)
	for (int i = (n-1 - 1)/2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		// �ټ���ѡ��С��
		AdjustDown(a, end, 0);
		--end;
	}
}

int main()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapSort(a, sizeof(a) / sizeof(HPDataType));

	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(HPDataType));
	HeapPush(&hp, 13);

	HeapDestory(&hp);

	return 0;
}


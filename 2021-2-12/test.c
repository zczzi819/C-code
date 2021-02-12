#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
	FILE *fp = fopen("test.log", "w");
	FILE*pFile = fp;
	if (pFile == NULL)
	{
		printf("fopen error\n");
		system("pause");
		return 1;
	}
	for (int c = 'a'; c <= 'z'; c++)
	{
		int pos = ftell(pFile);
		printf("%d\n", pos);//0,1,2,3,...........25
		fputc(c, pFile);

	}
	int b = ftell(fp);
	printf("%d\n", b);
	system("pause");
	return 0;
	/*FILE *pFile = fopen("test.log", "r");
	if (pFile == NULL)
	{
	printf("fopen error\n");
	system("pause");
	return 1;
	}
	int b = ftell(pFile);
	printf("%d\n",b);
	system("pause");
	return 0;
	}*/
}




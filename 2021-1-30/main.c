#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int main()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		menu();
		scanf("%d",&select);
		switch (select)
		{
			case 1:
				game();
				break;
			case 2:
				quit = 1;
				printf("Ҫ��Ҫ����һ��\n");
				break;
			default:
				printf("��������\n");
				break;

		}
	}
	printf("ByeBye\n");
}
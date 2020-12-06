#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int main()
{
	int quit = 0;
	int select = 0;
	
	while (!quit)
	{
		Menu();
		printf("请选择:");
		scanf("%d", &select);
		switch (select)
		{
			case 1:
				Game();
				break;
			case 2:
				quit = 1;
				break;
			default:
				printf("输入有误，请重新输入\n");
				break;
		}
	}
	system("pause");
	return 0;
}
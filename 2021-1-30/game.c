#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("########################\n");
	printf("###1.play   2.exit######\n");
	printf("########################\n");
	printf("select:");
}
void Computer(char board[][COL], int row, int col)
{
	while (1)
	{

		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] = ' ')
		{
			board[x][y] = C_COLOR;
			break;
		}


	}
}
void PlayerMove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	int quit = 0;
	while (!quit)
	{

		printf("请输入你的坐标：");
		scanf("%d %d", &x, &y);
		if (x <1 || x > 3 || y < 1 || y > 3)
		{
			printf("输入有误\n");
			continue;
		}
		if (board[x-1][y-1]!=' ')
		{
			printf("该位置已经被占用\n");
			continue;
		}
		board[x - 1][y - 1] = P_COLOR;
		quit = 1;
	}
}
void Showboard(char board[][COL], int row, int col)
{
	printf("   1  | 2 |  3\n");
	printf("---------------\n");
	for (int i = 0; i < row; i++)
	{
		printf("%d |",i+1);
		for (int j = 0; j < col; j++)
		{
			printf(" %c |",board[i][j]);
		}
		printf("\n---------------\n");
	}
	


}
char Judge(char board[][COL], int row, int col)
{
	for (int i = 0; i < ROW; i++)
	{
		if (board[i][0]==board[i][1] && board[i][1] ==board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (int j = 0; j < COL; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][0];
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return NEXT;
			}
		}
	}
	return DRAW;
}

void game()
{
	srand((unsigned long)time(NULL));
	char board[ROW][COL];
	memset(board,' ',sizeof(board));
	char result = 'X';
	do{
		Showboard(board,ROW,COL);
		PlayerMove(board, ROW, COL);
		result=Judge(board, ROW, COL);
		if (result != NEXT)
		{
			break;
		}
		Computer(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != NEXT)
		{
			break;
		}
	} while (1);
	if (P_COLOR == result)
	{
		printf("你赢了\n");
	}
	else if (C_COLOR == result)
	{
		printf("你输了\n");
	}
	else
	{
		printf("和棋了\n");
	}
	Showboard(board, ROW, COL);
}
#include"game.h"
void menu(void);
void game(void);
void test(void);
int main()
{
	test();
	return 0;
}
void menu()
{
	printf("\n*************************\n");
	printf("*************************\n");
	printf("******1.play  0.exit*****\n");
	printf("*************************\n");
	printf("*************************\n");
	printf("\n");
}
void game()
{
	//布置好的雷的信息
	char mine[ROWS][COLS];
	//排查好的雷的信息
	char show[ROWS][COLS];
	//初始化数组
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//显示棋盘
	DisplayBoard(show, ROW, COL);
	SetMine(mine,ROW,COL);
	/*DisplayBoard(mine, ROW, COL);*/
	//扫描
	FindMine(mine,show,ROW,COL);
	
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d",&input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0: 
				printf("退出游戏\n");
				break;
			default :
				printf("选择错误，请重新选择\n");
				break;
		}
	} while (input);
}
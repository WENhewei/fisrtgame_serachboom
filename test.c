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
	//���úõ��׵���Ϣ
	char mine[ROWS][COLS];
	//�Ų�õ��׵���Ϣ
	char show[ROWS][COLS];
	//��ʼ������
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//��ʾ����
	DisplayBoard(show, ROW, COL);
	SetMine(mine,ROW,COL);
	/*DisplayBoard(mine, ROW, COL);*/
	//ɨ��
	FindMine(mine,show,ROW,COL);
	
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d",&input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0: 
				printf("�˳���Ϸ\n");
				break;
			default :
				printf("ѡ�����������ѡ��\n");
				break;
		}
	} while (input);
}
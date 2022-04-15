#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
// '1'-'0'=1
//'3'-'0'=3
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
		return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j = 0;
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf(" %d ",i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d ",i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ",board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = easy_count;
	while (count)
	{
		int x = rand()%ROW+1;
		int y = rand()%ROW + 1;//1-9
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	//9*9-10=71
	while (win<row*col-easy_count)
	{
		printf("�������Ų��׵����꣺>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			//����
			if (mine[x][y] == '1')
			{
				printf("���ź��㱻ը����\n");
				DisplayBoard(mine,row,col);
				break;
			}
			//����
			else
			{
				//����X,Y��Χ�м�����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++; 
			}
		}
		else
		{
			//����Ƿ�
			printf("��������Ƿ�������������\n");
			break;
		}
	}
	if (win == row * col - easy_count)
	{
		printf("��ϲ��ɨ�׳ɹ�������\n");
		DisplayBoard(mine,row,col);
	}
}
//ɨ�׵�չ��
//1.���겻���׸ĳɿո�  2.��������ΧҲû����  3.��������Χ����������������ж�   �����ĵݹ�  4.ֻҪ������Ͳ�չ��
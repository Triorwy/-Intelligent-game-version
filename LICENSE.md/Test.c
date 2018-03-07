#define  _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu1()
{
	printf("******************************\n");
	printf("****  欢迎来到三子棋游戏  ****\n");
	printf("****   1.玩游戏  0.退出   ****\n");
	printf("******************************\n");
}
void menu2()
{
	printf("*****************************\n");
	printf("****     1.简单模式      ****\n");
	printf("****     2.困难模式      ****\n");
	printf("*****************************\n");

}

void menu3()
{
	printf("******************************\n");
	printf("****      1.玩家先走      ****\n");
	printf("****      2.电脑先走      ****\n");
	printf("******************************\n");

}

void game()
{
	int input2 = 0;
	int input3 = 0;
	char  board[ROW][COL]= {0};
	menu2();
	fflush(stdin);
	printf("请选择模式\n");
	scanf("%d",&input2);
	system("cls");
	menu3();
	fflush(stdin);
	printf("请选择谁先手\n");
	scanf("%d",&input3);
	switch(input3)
	{
	case 1:
		PlayerStartMove(board,ROW,COL,input2);
		break;
	case 2:
		CompeterStartMove(board,ROW,COL,input2);
		break;
	default:
		printf("输入错误，请重新输入\n");
		break;
	}
}
void test()
{
	int input1 = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu1();
		printf("请输入：");
		fflush(stdin);
		scanf("%d",&input1);
		system("cls");
		switch(input1)
		{
		case 0:
			exit(0);
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}while(input1);
}
int main()
{

	test();
	system("pause");
	return 0;

}

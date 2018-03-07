#define  _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void InitBoard(char board[ROW][COL],int row,int col)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for(i = 0;i<row;i++)
	{
		for(j = 0;j<col;j++)
		{
			board[i][j] = ' ';//初始化为空
		}
	
	}
}

void DisplayBoard(char board[ROW][COL],int row,int col)//打印棋盘
{
	int i = 0;
	for(i = 0;i < ROW;i++)
	{
		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		if(i < ROW - 1)
		{
			printf("---|---|---\n");
		}
		
	}
}
 static int Isfull(char board[ROW][COL],int row,int col)//判断是否棋盘下满
{
	int i = 0;
	int j = 0;
	for(i = 0;i< row;i++)
	{
		for(j= 0;j< col;j++)
		{
			if(board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char Iswin(char board[ROW][COL],int row,int col)//判断游戏是否出现赢家
{
	int i = 0;
	char ret = 0;
	for(i = 0;i < row;i++)
	{
		if((board[i][0]==board[i][1])&&(board[i][1]==board[i][2])&&(board[i][1]!= ' '))//横着三个棋子相等
		{
			return board[i][1];
		}
	}

	for(i = 0;i < col;i++)
	{
		 if((board[0][i]==board[1][i])&&(board[1][i]==board[2][i])&&(board[1][i]!=' '))//竖着三个棋子相等
		{
			return board[1][i];
		}
	}

	if((board[0][0]==board[1][1])&&(board[2][2]==board[1][1])&&(board[1][1]!=' '))//左对角三个棋子相等
		{
			return board[1][1];
		}

	else if((board[0][2]==board[1][1])&&(board[2][0]==board[1][1])&&(board[1][1]!=' '))//右对角三个棋子相等
		{
			return board[1][1];
		}
	if(Isfull(board,row,col))//判断棋盘是否为满
	{
		return 'q';
	}
	else
	{
		return '#';
	}
}
void CompeterEasy(char board[ROW][COL],int row,int col)//电脑简单模式
{
	int x = 0;
	int y = 0;
	while(1)
	{
		x = rand()%3;
		y = rand()%3;
		if(board[x][y] == ' ')
		{
			board[x][y] = 'D';
			break;
		}
		
	}
}
int CompeterDiff(char board[ROW][COL],int row,int col)//电脑困难模式
{
	int i = 0;
	for(i = 0;i < row;i++) //判断每一行上是否有两个相同的棋子
	{
		if((board[i][0]==board[i][1])&&(board[i][2]==' ')&&board[i][0]!=' ')
		{
			board[i][2] ='D';
			return 1;
		}
		if((board[i][0]==board[i][2])&&(board[i][1]==' ')&&board[i][2]!=' ')
		{
			board[i][1] ='D';
			return 1;
		}
		if((board[i][2]==board[i][1])&&(board[i][0]==' ')&&board[i][1]!=' ')
		{
			board[i][0] ='D';
			return 1;
		}
	}
	for(i = 0;i < col;i++) //判断每一列上是否有两个相同的棋子
	{
		if((board[0][i]==board[1][i])&&(board[2][i]==' ')&&board[0][i]!=' ')
		{
			board[2][i] ='D';
			return 1;
		}
		if((board[0][i]==board[2][i])&&(board[1][i]==' ')&&board[2][i]!=' ')
		{
			board[1][i] ='D';
			return 1;
		}
		if((board[2][i]==board[1][i])&&(board[0][i]==' ')&&board[1][i]!=' ')
		{
			board[0][i] ='D';
			return 1;
		}
	}
	//判断主对角线上是否有两个相同的棋子
	if((board[0][0]==board[1][1])&&(board[2][2]==' ')&&(board[0][0]!=' ')) 
		{
			board[2][2]='D';
			return 1;
			
		}
	if((board[2][2]==board[1][1])&&(board[0][0]==' ')&&(board[1][1]!=' ')) //做对角线
		{
			board[0][0]='D';
			return 1;
			
		}
	if((board[0][0]==board[2][2])&&(board[1][1]==' ')&&(board[2][2]!=' ')) //做对角线
		{
			board[1][1]='D';
			return 1;
		}
	//判断副对角线上是否有两个相同的棋子
	if((board[0][2]==board[2][0])&&(board[1][1]==' ')&&(board[0][2]!=' ')) 
		{
			board[1][1]='D';
			return 1;
		}
	if((board[0][2]==board[1][1])&&(board[2][0]==' ')&&(board[1][1]!=' ')) //做对角线
		{
			board[2][0]='D';
			return 1;
		}
	if((board[2][0]==board[2][2])&&(board[0][2]==' ')&&(board[2][2]!=' ')) //做对角线
		{
			board[0][2]='D';
			return 1;
		}
	return 0;
}
void PlayerMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	while(1)
	{
		printf("请输入->(x,y)");
		fflush(stdin);
		scanf("%d,%d",&x,&y);
		if(x>=1 && x<=3 && y>=1 && y<=3)
		{
			if(board[x-1][y-1] == ' ')
			{
				
				board[x-1][y-1] = '*';
				break;
			
			}
			else 
			{
				printf("坐标被占，请重新输入\n");
				continue;
			}

		}
		else
		{
			printf("输入坐标不在棋盘内\n");
			continue;
		}
	}	
}

void CompeterStartMove(char board[ROW][COL],int row,int col,int input2)
{
	char ret;
	InitBoard(board,row,col);//初始化
	DisplayBoard(board,row,col);//打印棋盘
	do
	{
		CompeterSelect(board,row,col,input2);//电脑走
		DisplayBoard(board,row,col);//打印棋盘
		ret = Iswin(board,row,col);//判断是否赢了
		if(ret != '#')
		{
			break;
		}
		PlayerMove(board,row,col);//玩家走
		DisplayBoard(board,row,col);
		ret = Iswin(board,row,col);
		if(ret != '#')
		{
			break;
		}
	}while(ret == '#');
	if(ret == 'D')
	{
		printf("你真弱，电脑赢了，好好练练吧\n");
	}
	else if(ret == '*')
	{
		printf("恭喜你，赢了\n");
	}
	else if(ret == 'q')
	{
		printf("平局\n");
	
	}
}

void PlayerStartMove(char board[ROW][COL],int row,int col,int input2)
{
	char ret = 0;
	InitBoard(board,row,col);
	DisplayBoard(board,row,col);
	while(1)
	{
		PlayerMove(board,row,col);
		DisplayBoard(board,row,col);
		ret = Iswin(board,row,col);
		{
			if(ret != '#')
			{
				break;
			}
		}
		CompeterSelect(board,row,col,input2);
		DisplayBoard(board,row,col);
		ret = Iswin(board,row,col);
		{
			if(ret != '#')
			{
				break;
			}
		}
	}
	if('*'==ret)
	{
		printf("恭喜你，赢了\n");
	}
	else if('D' == ret)
	{
		printf("你真弱,电脑赢了，好好练练吧\n");
	}
	else if('q'== ret)
	{
		printf("平局\n");
	}

}

void CompeterSelect(char board[ROW][COL],int row,int col,int input2)//选择电脑简单还是困难模式
{
	int ret=0;
	printf("电脑走\n");
	if(Easy == input2)
	{
		CompeterEasy(board,row,col);
	}
	if(Diff == input2)
	{	
		ret = CompeterDiff(board,row,col);
		if(0 == ret) //电脑无法给出最优位置，则随机给值
		{
			CompeterEasy(board,row,col);	
		}
	}
	
}

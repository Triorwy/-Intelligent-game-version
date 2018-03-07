#ifndef _GAME_H_
#define _GAME_H_

#include<stdio.h>
#include<windows.h>
#include<time.h>

#define ROW 3
#define COL 3

enum ED
{
	Easy = 1,
	Diff 
};

void InitBoard(char board[ROW][COL],int row,int col);//初始化棋盘函数
void DisplayBoard(char board[ROW][COL],int row,int col);//打印棋盘函数
void CompeterEasy(char board[ROW][COL],int row,int col);//简单电脑走函数
int CompeterDiff(char board[ROW][COL],int row,int col);//困难电脑走函数
void CompeterStartMove(char board[ROW][COL],int row,int col,int input2);//电脑先走函数
void PlayerMove(char board[ROW][COL],int row,int col,int input2);//人先走函数
void CompeterSelect(char board[ROW][COL],int row,int col,int input2);//电脑选择模式函数
char Iswin(char board[ROW][COL],int row,int col); //判断谁赢函数


#endif

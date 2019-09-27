/*
 *
 */
#include<stdio.h>
#include<ctype.h>
char s[10][10]={{'E', 'E', 'E', 'E', 'E'},
                {'E', 'E', 'M', 'E', 'E'},
                {'E', 'E', 'E', 'E', 'E'},
                {'E', 'E', 'E', 'E', 'E'}};

int judge(int x,int y)//
{
        /*上下左右上左 上右 下左 下右*/
	int count=0;
	if(x<0||y<0||x>=4||y>=5)
		return 1;
	if(((x-1>=0)&&y>=0&&(s[x-1][y]=='M'))||(x+1>=0&&y>=0&&s[x+1][y]=='M')||(y-1>=0&&x>=0&&s[x][y-1]=='M')||(y+1>=0&&x>=0&&s[x][y+1]=='M')||((x-1>=0&&y-1>=0)&&s[x-1][y-1]=='M')||((x-1>=0&&y+1>=0)&&s[x-1][y+1]=='M')||((x+1>=0&&y-1>=0)&&s[x+1][y-1]=='M')||((x+1>=0&&y+1>=0)&&s[x+1][y+1]=='M'))
	{
		count++;
		s[x][y]=count+'0';
		print();
	}
	else
	{
		if((isdigit(s[x][y])==0)&&s[x][y]!='B')
		{
		s[x][y]='B';
		judge(x-1,y);
		judge(x+1,y);
		judge(x,y-1);
		judge(x,y+1);
		judge(x-1,y-1);
		judge(x-1,y+1);
		judge(x+1,y-1);
		judge(x+1,y+1);
		}
	}
        

		  
}
void print()
{
	printf("-----------------\n");
	int i,j;
	for(i=0;i<4;i++)
	{	for(j=0;j<5;j++)
		{
			printf("%c ",s[i][j]);
		}
	printf("\n");
	}
}
int main()
{
   int i,j;
   int x=2;
   int y=2;
   int ret=0;
   for(i=0;i<4;i++)
   {
	   for(j=0;j<5;j++)
	   {
		   if(s[i][j]=='M'&&i==x&&j==y)
		   {
			   s[i][j]='X';
			   printf("xxxx\n");
			   break;
		   }
		   else if(i==x&&j==y)
		   {
                   //如果没有一个相邻地雷的'E' 那就修改'B',并且所有和其相邻的方块应该被递归揭露
		   //如果一个相邻 就修改数字 表示相邻地雷的数量
		   //首先判断方块是不是在面板内。如果不是 直接返回面板 leetcode不需要
		   // 1.然后判断这个方块的上下左右还有四个对角线 有没有地雷
		   // 2.如果有 修改方块的数字为（1-8) 表示相邻地雷数量
		   // 3.如果没有 就修改为‘B’ 并且所有和其相邻方块都被递归揭露go 1                  // 4.如果没有更多方块可以被揭露 就返回面板。
		       judge(i,j);//没有更多方块揭露或者周围有地雷就显示数字返回面板                   
		       print();
		   }
	   }
   }
}

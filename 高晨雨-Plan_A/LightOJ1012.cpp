//DFS
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define Max 25
char Map[Max][Max];
int r,c,sum;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void DFS(int x,int y)
{
	Map[x][y]='#';
	sum++;
	int xx,yy;
	for(int i=0;i<4;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if(xx>=1&&yy>=1&&xx<=r&&yy<=c)
		{
			if(Map[xx][yy]=='.')
				DFS(xx,yy);
		}
	}
}
int main()
{
	int T;
	cin>>T;
	for(int kase=1;kase<=T;kase++)
	{
		memset(Map,'#',sizeof(Map));
		cin>>c>>r;
		int x,y;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				cin>>Map[i][j];
				if(Map[i][j]=='@')
				{
					x=i;
					y=j;
				}
			}
		sum=0;
		DFS(x,y);
		printf("Case %d: %d\n",kase,sum);
	}
}

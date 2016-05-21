//dfs
#include<bits/stdc++.h>
using namespace std;

int ax[4]={0,0,-1,1};
int ay[4]={1,-1,0,0};
char m[25][25];
int w,h;
int sx,sy;
int sum;

void dfs(int x,int y)
{
	sum++;
	m[x][y]='#';
	for(int i=0;i<4;i++)
	{
		int xx=x+ax[i];
		int yy=y+ay[i];
		if(xx>=0&&xx<h&&yy>=0&&yy<w)
		{
			if(m[xx][yy]=='.')
			{
				dfs(xx,yy);
			}
		}
	}
}

int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cin>>w>>h;
		sum=0;

		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cin>>m[i][j];
				if(m[i][j]=='@')
				{
					sx=i;
					sy=j;
				}
			}
		}

		dfs(sx,sy);

		printf("Case %d: %d\n",z,sum);
	}
	return 0;
}

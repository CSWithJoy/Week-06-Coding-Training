//数字三角形问题变形
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 205
int Map[MAX][MAX];
int a,b;
void DP()
{
	for(int i=2;i<=a;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1) Map[i][j]+=Map[i-1][j];
			else if(j==i) Map[i][j]+=Map[i-1][j-1];
				 else Map[i][j]+=max(Map[i-1][j],Map[i-1][j-1]);
		}
	}
	for(int i=a+1;i<=b;i++)
	{
		for(int j=1;j<=b-i+1;j++)
		{
			Map[i][j]+=max(Map[i-1][j],Map[i-1][j+1]);
		}
	}
}
int main()
{
	int T;
	cin>>T;
	for(int kase=1;kase<=T;kase++)
	{
		cin>>a;
		b=a*2-1;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cin>>Map[i][j];
			}
		}
		for(int i=a+1;i<=b;i++)
		{
			for(int j=1;j<=(b+1-i);j++)
			{
				cin>>Map[i][j];
			}
		}
		DP();
		printf("Case %d: %d\n",kase,Map[b][1]);
		//cout<<Map[b][1]<<endl;
	}
	return 0;
}

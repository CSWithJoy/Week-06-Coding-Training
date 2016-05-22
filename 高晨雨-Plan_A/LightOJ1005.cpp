//n>c时，棋子数大于格子边长是方法数为0
//n<=c时，棋子一个一个放，放第一个有c*c种方案，第二个有(c-1)*(c-1)种，以此类推，由于棋子不分先后，最后要除n!
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

long long dp[35][35];

void DP()
{
	int i,j;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=30;i++)
	{
		dp[i][0]=1;
		dp[i][1]=i*i;
	}
	for(i=2;i<=30;i++)
	{
		for(j=2;j<=i;j++)
		{
			dp[i][j]=dp[i][1]*dp[i-1][j-1]/j;
		}
	}
}
int main()
{
	int r,n,kase,T;
	DP();
	cin>>T;
	for(kase=1;kase<=T;kase++)
	{
		cin>>r>>n;
		printf("Case %d: %lld\n",kase,dp[r][n]);
	}
	return 0;
}

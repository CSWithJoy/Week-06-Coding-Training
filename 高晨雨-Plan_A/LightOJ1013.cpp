//字符串的最短长度就是两个字符串的长度和-两个字符串的LCS
//用ans[i][j][k]表示该字符串当前有i个字符，包含了第一个字符串的j个字符，第2个字符串的k个字符的种类数
//状态转移方程：如果s1[j] = s2[k] ：ans[i + 1][j + 1][k + 1] += ans[i][j][k]
//如果s1[j] != s2[k] ：ans[i + 1][j][k + 1] += ans[i][j][k] ，ans[i + 1][j + 1][k] += ans[i][j][k]
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define N 35
char s1[N],s2[N];
int len1,len2,cas=1;
int dp[N][N];
long long ans[N*2][N][N];

int LCS()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[len1][len2];
}
void solve()
{
	int len=len1+len2-LCS();
	memset(ans,0,sizeof(ans));
	ans[0][0][0]=1;
	for(int i=0;i<=len;i++)
	{
		for(int j=0;j<=len1;j++)
		{
			for(int k=0;k<=len2;k++)
			{
				if(ans[i][j][k])
				{
					if(s1[j+1]==s2[k+1]) ans[i+1][j+1][k+1]+=ans[i][j][k];
					else
					{
						ans[i+1][j][k+1]+=ans[i][j][k];
						ans[i+1][j+1][k]+=ans[i][j][k];
					}
				}
			}
		}
	}
	printf("Case %d: %d %lld\n", cas++, len, ans[len][len1][len2]);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%s%s",s1+1,s2+1);
		len1=strlen(s1+1);
		len2=strlen(s2+1);
		solve();
	}
	return 0;
}

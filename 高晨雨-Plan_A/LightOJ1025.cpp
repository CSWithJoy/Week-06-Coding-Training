//状态转移方程：S[j]!=S[k]时，DP[j][k]=DP[j][k-1]+DP[j+1][k]-DP[j+1][k-1];
//				S[j]==S[k]时，DP[j][k]=DP[j][k-1]+DP[j+1][k]+1;
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
long long DP[80][80];
char S[80];
int main()
{
	int T;
	cin>>T;
	for(int kase=1;kase<=T;kase++)
	{
		int len;
		memset(S,'\0',sizeof(S));
		scanf("%s",S+1);
		len=strlen(S+1);
		memset(DP,0,sizeof(DP));
		for(int i=1;i<=len;i++)
		{
			for(int j=1;j<=len;j++)
			{
				int k=j+i-1;
				DP[j][k]=DP[j+1][k]+DP[j][k-1]-DP[j+1][k-1];
				if(S[j]==S[k])
					DP[j][k]+=DP[j+1][k-1]+1;
			}
		}
		printf("Case %d: %lld\n",kase,DP[1][len]);
	}
	return 0;
}

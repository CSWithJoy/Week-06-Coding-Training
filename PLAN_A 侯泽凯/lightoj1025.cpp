//区间dp
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL   dp[100][100];
char s[100];

int main ()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        scanf ("%s",s+1);
        int len=strlen(s+1);
        memset(dp,0,sizeof(dp));

        for (int i=0; i<len; i++)//i+1是字符串长度
		{
			int l,r;
			for (l=1;l+i<=len;l++)//取l~r的字符串
            {
                r=l+i;
                dp[l][r]+=dp[l+1][r];
                dp[l][r]+=dp[l][r-1];

                if (s[l]==s[r])
				{
					dp[l][r]+=1;
				}
                else
				{
					dp[l][r]-=dp[l+1][r-1];
				}
            }
		}

        printf ("Case %d: %lld\n",z,dp[1][len]);
    }
    return 0;
}

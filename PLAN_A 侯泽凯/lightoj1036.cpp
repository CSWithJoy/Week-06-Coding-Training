//线性DP+记忆化搜索
#include<bits/stdc++.h>
using namespace std;

int n,m;
int  u[505][505];
int  r[505][505];
int dp[505][505];

int main()
{
    int t;
    cin>>t;

	//预处理
    for(int z=1;z<=t;z++)
	{
        cin>>n>>m;

		//（i,j）位左边的U矿个数
        for(int i = 1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int x;
                scanf("%d", &x);
                u[i][j] = u[i][j-1]+x;
            }
        }

		//（i,j）位左边的R矿个数
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                r[i][j]=r[i-1][j]+x;
            }
        }

        memset(dp, 0, sizeof dp);

		//从（1，1）->（n，m）记忆化搜索
        for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				//每一步要么往上走到头，要么往左走到头。
				dp[i][j] = max(dp[i-1][j]+u[i][j] , dp[i][j-1]+r[i][j]);
			}
		}

        printf("Case %d: %d\n",z,dp[n][m]);
    }
    return 0;
}

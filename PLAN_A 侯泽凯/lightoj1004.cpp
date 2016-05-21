//三角形的变形题
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[205][205];
int a[205][205];

int main()
{
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++)
    {
        memset(dp, 0, sizeof(dp));
        int n;
        scanf("%d", &n);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++)
                scanf("%d", &a[i][j]);

        for(int i = n + 1; i <= 2 * n - 1; i++)
            for(int j = 1; j <= 2 * n - i; j++)
                scanf("%d", &a[i][j]);

        dp[1][1] = a[1][1];
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
            }
        }

        for(int i = n + 1; i <= 2 * n - 1; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + a[i][j]);
            }
        }

        printf("Case %d: %d\n", ca, dp[2 * n - 1][1]);
    }
}

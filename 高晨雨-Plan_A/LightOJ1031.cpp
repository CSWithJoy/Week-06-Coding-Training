//区间DP
//状态转移方程：if(k!=j)    dp[j][i+j] = max(dp[j][i+j], sum[k-1] - sum[j-1] - dp[k][i+j]);
//              if(k!=i+j)  dp[j][i+j] = max(dp[j][i+j], sum[i+j] - sum[k] - dp[j][k]);
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int LEN = 101;
int n, dp[LEN][LEN], num[LEN], sum[LEN];

int main()
{
    int T, kase = 1;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> num[i];
        sum[0] = 0;
        for(int i=1; i<=n; i++) sum[i] = sum[i-1] + num[i];
        for(int i=0; i<n; i++){
            for(int j=1; j+i<=n; j++){
                dp[j][i+j] = sum[i+j] - sum[j-1];
                for(int k=j; k<=j+i; k++){
                    if(k!=j)
                        dp[j][i+j] = max(dp[j][i+j], sum[k-1] - sum[j-1] - dp[k][i+j]);
                    if(k!=i+j)
                        dp[j][i+j] = max(dp[j][i+j], sum[i+j] - sum[k] - dp[j][k]);
                }
            }
        }
        cout << "Case " << kase++ << ": " << dp[1][n] << endl;
    }
    return 0;
}

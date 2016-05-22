#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100000;

const int MOD=1000000007;

using namespace std;

int t,n,a[maxn+10],in[maxn+10],dp[maxn+10];

int lowbit(int x)
{
    return x & (-x);
}
void modify(int x,int add)
{
    while(x<=n)
    {
        dp[x]+=add;
        dp[x]%=MOD;
        x+=lowbit(x);
    }
}

int get_sum(int x)
{
    int ret=0;
    while(x!=0)
    {
        ret=(ret+dp[x])%MOD;
        x-=lowbit(x);
    }
    return ret;
}

int cmp(int x,int y){
     if(a[x]!=a[y]) return a[x]<a[y];
     return x>y;
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),in[i]=i;
        sort(in+1,in+n+1,cmp);
        for(int i=1;i<=n;i++) {
                modify(in[i],get_sum(in[i]-1)+1);
        }
        printf("Case %d: %d\n",h,get_sum(n));
    }
    return 0;
}

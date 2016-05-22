#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

//const int maxn=;

using namespace std;

int n,a,b,c,d;

int main()
{
    while(scanf("%d%d%d%d%d",&n,&a,&b,&c,&d)!=EOF){
        __int64 ans=0;
        for(int i=1;i<=n;i++){
                if(a-d+i>=1&&a-d+i<=n&&b-c+i>=1&&b-c+i<=n&&a+b-c-d+i>=1&&a+b-c-d+i<=n) ans++;
        }
        printf("%I64d\n",ans*n);
    }
    return 0;
}

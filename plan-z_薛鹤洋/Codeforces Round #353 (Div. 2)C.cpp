#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100000;

using namespace std;

int n,x;

int main()
{
    while(scanf("%d",&n)!=EOF){
        long long sum=0;
        int ans=-inf;
        map<long long,int> m;
        for(int i=0;i<n;i++){
                scanf("%d",&x);
                sum+=x;
                m[sum]++;
                ans=max(ans,m[sum]);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}

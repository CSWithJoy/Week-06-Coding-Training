#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int mx=20000;
/*
上周没有解决的问题，貌似这种划分都是用并查集做的。
*/
int fa[mx*2+5],rk[mx*2+5],x[100005],y[100005];
bool has[mx*2+5];
int find(int x){
    return ~fa[x]?fa[x]=find(fa[x]):x;
}
void merge(int x, int y)
{
    x=find(x),y=find(y);
    if(x==y)return;
    fa[y]=x;
    rk[x]+=rk[y];
}
int main(){
    int T,n,ans,cnt,u,v,fau,fav,i;
    int nc(1);
    scanf("%d",&T);
    while(T--){
        memset(fa,-1,sizeof(fa));
        memset(rk,0,sizeof(rk));
        memset(has,0,sizeof(has));
        scanf("%d",&n);
        ans=cnt=0;
        while(n--){
            scanf("%d%d",&u,&v);
            x[cnt]=u;
            y[cnt++]=v;
            has[u]=has[v]=has[u+mx]=has[v+mx]=1;
            rk[u]=rk[v]=1;
        }
        while(cnt--){
            merge(x[cnt],y[cnt]+mx);
            merge(x[cnt]+mx,y[cnt]);
        }
        for(i=1;i<=mx*2;++i)
            if(has[i]&&fa[i]==-1)
            {
                fau=i;
                fav=find(i + mx);
                ans+=max(rk[fau],rk[fav]);
                fa[fau]=fa[fav]=0;
            }
        printf("Case %d: %d\n",nc++,ans);
    }
    return 0;
}

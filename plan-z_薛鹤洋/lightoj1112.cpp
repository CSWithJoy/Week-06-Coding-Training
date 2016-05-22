#include <bits/stdc++.h>

using namespace std;

const int maxn=100000;

int t,n,q,x,v,order;

int a[maxn+10],bit[maxn+10];

int lowbit(int x)
{
    return x & (-x);
}
void modify(int x,int add)
{
    while(x<=n)
    {
        bit[x]+=add;
        x+=lowbit(x);
    }
}

int get_sum(int x)
{
    int ret=0;
    while(x!=0)
    {
        ret=(ret+bit[x]);
        x-=lowbit(x);
    }
    return ret;
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        printf("Case %d:\n",h);
        scanf("%d%d",&n,&q);
        memset(bit,0,sizeof(bit));
        for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        modify(i,a[i]);
        }
        for(int i=1;i<=q;i++){
                scanf("%d",&order);
                if(order==1){
                scanf("%d",&x);
                int t=get_sum(x+1)-get_sum(x);
                printf("%d\n",t);
                modify(x+1,-t);
                } else if(order==2){
                scanf("%d%d",&x,&v);
                modify(x+1,v);
                } else {
                scanf("%d%d",&x,&v);
                x=get_sum(x);
                v=get_sum(v+1);
                printf("%d\n",v-x);
                }
        }
    }
    return 0;
}

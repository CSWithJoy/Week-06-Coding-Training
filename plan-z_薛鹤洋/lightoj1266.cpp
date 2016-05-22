#include <bits/stdc++.h>

using namespace std;

const int maxn=1000;

int a[maxn+10][maxn+10],c[maxn+10][maxn+10];

int Lowbit(int t)
{
    return t&(-t);
}

void add(int x, int y)
{
    int i=y;
    while(x<=maxn+10)
    {
        y=i;
        while(y<=maxn+10)
        {
            c[x][y]++;
            y+=Lowbit(y);
        }
        x+=Lowbit(x);
    }
}

int Sum(int x, int y)
{
    int i=y, sum=0;
    while(x>0)
    {
        y=i;
        while(y>0)
        {
            sum+=c[x][y];
            y-=Lowbit(y);
        }
        x-=Lowbit(x);
    }
    return sum;
}

int t,q,X1,Y1,X2,Y2,order;

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        memset(a,0,sizeof(a)),memset(c,0,sizeof(c));
        printf("Case %d:\n",h);
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
                scanf("%d",&order);
                if(order==0){
                       scanf("%d%d",&X1,&Y1);
                       if(!a[X1+1][Y1+1]){
                        a[X1+1][Y1+1]=1;
                        add(X1+1,Y1+1);
                       }
                } else {
                    scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
                    printf("%d\n",Sum(X2+1,Y2+1)-Sum(X2+1,Y1)-Sum(X1,Y2+1)+Sum(X1,Y1));
                }
        }
    }
    return 0;
}

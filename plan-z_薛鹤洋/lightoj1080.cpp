/*
线段树 区间更新 单点查询
*/
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100000;

using namespace std;

char bin[maxn+10],ch[10];

int t,n,q,x,y,c;

long long tree[maxn*4+100],lazy[maxn*4+100];

void PushDown(int p,int L){
    if(lazy[p]){
        lazy[p*2]+=lazy[p];
        lazy[p*2+1]+=lazy[p];
        tree[p*2]+=lazy[p]*(L-(L>>1));
        tree[p*2+1]+=lazy[p]*(L>>1);
        lazy[p]=0;
    }
}

void build(int p,int l,int r){
    if(l==r) {tree[p]=bin[l]-'0';return ;}
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p]=tree[p*2]+tree[p*2+1];
}

void update(int p,int l,int r,int x,int y,int num){
    if(x<=l&&r<=y){
        lazy[p]+=num;
        tree[p]+=(__int64)num*(r-l+1);
        return ;
    }
    PushDown(p,r-l+1);
    int mid=(l+r)/2;
    if(y<=mid) update(p*2,l,mid,x,y,num);
    else if(x>mid)  update(p*2+1,mid+1,r,x,y,num);
    else {
        update(p*2,l,mid,x,y,num);
        update(p*2+1,mid+1,r,x,y,num);
    }
    tree[p]=tree[p*2]+tree[p*2+1];
}

long long find(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y) return tree[p];
    PushDown(p,r-l+1);
    int mid=(l+r)/2;
    if(y<=mid) return find(p*2,l,mid,x,y);
    if(x>mid) return find(p*2+1,mid+1,r,x,y);
    return (find(p*2,l,mid,x,y)+find(p*2+1,mid+1,r,x,y));
}

void init(int h){
 printf("Case %d:\n",h);
 memset(tree,0,sizeof(tree));
 memset(lazy,0,sizeof(lazy));
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        init(h);
        scanf("%s",bin+1);
        n=strlen(bin+1);
        //build(1,1,n);
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
                scanf("%s",ch);
                if(ch[0]=='I') {
                        scanf("%d%d",&x,&y);
                        update(1,1,n,x,y,1);
                } else if(ch[0]=='Q') {
                     scanf("%d",&c);
                     int x=find(1,1,n,c,c);
                     if(bin[c]=='1') {
                        if(x%2!=0) printf("0\n");
                        else printf("1\n");
                     } else {
                         if(x%2!=0) printf("1\n");
                         else printf("0\n");
                     }
                }
        }
    }
    return 0;
}

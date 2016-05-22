#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
//本来准备2倍扩展的，结果。。。
//参考了网上的题解，原来3倍可以不用特判
//还是需要经验
const int N=3*100;
int cas,tmp;
bool flag;
int mp[N][N];
int m,n;
int dfs(int x,int y)
{
    mp[x][y]=1;
    tmp++;
    if(x==0||x==(3*m-1)||y==0||y==(3*n-1)) flag=1;
    if(x>0 && mp[x-1][y]==0) dfs(x-1,y);
    if(y>0 && mp[x][y-1]==0) dfs(x,y-1);
    if(x<(3*m-1)&&mp[x+1][y]==0) dfs(x+1,y);
    if(y<(3*n-1)&&mp[x][y+1]==0) dfs(x,y+1);
}
int main()
{
    int T=1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        memset(mp,0,sizeof(mp));
        for(int i=0;i<m;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='/')
                {
                    mp[3*i][3*j+2]=1;
                    mp[3*i+1][3*j+1]=1;
                    mp[3*i+2][3*j]=1;
                }
                else if(s[j]=='\\')
                {
                    mp[3*i][3*j]=1;
                    mp[3*i+1][3*j+1]=1;
                    mp[3*i+2][3*j+2]=1;
                }
            }
        }
        int ans=0;
        cas=0,tmp=0,flag=false;
        for(int i=0;i<3*m;i++)
        {
            for(int j=0;j<3*n;j++)
            {
                if(mp[i][j]==0)
                {
                    dfs(i,j);
                    if(flag==false){
                        ans=max(tmp,ans);
                        cas++;
                    }
                    flag=false;
                    tmp=0;
                }
            }
        }
        printf("Maze #%d:\n",T++);
        if(cas==0)
            printf("There are no cycles.\n");
        else
            printf("%d Cycles; the longest has length %d.\n",cas,ans/3);
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int vis[4000];
int a[105];

int main(){
	int T;
	cin>>T;
	while(T--){
        int n,p;
        scanf("%d%d",&n,&p);
        for(int i=0;i<p;i++){
            cin>>a[i];
        }
        memset(vis,0,sizeof(vis));
        for(int i=0;i<p;i++){
            for(int j=0;j<=n;j+=a[i]){
                vis[j]=1;
            }
        }
        for(int i=0;i<=n;i+=7){
            vis[i]=0;
        }
        for(int i=6;i<=n;i+=7)
            vis[i]=0;
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=vis[i];
        cout<<ans<<endl;
	}
	return 0;
}

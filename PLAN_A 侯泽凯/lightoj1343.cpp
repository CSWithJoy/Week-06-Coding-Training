//二维树状数组，long long会wa。。。
#include<bits/stdc++.h>
using namespace std;

struct point
{
	int x;
	int y;
	int s;
}cur;

int a[505];
unsigned c[505][505];
int n;
vector<point>p;

bool cmp(point a,point b)
{
	if(a.s==b.s&&a.x==b.x)
	{
		return a.y<b.y;
	}
	else if(a.s==b.s)
	{
		return a.x<b.x;
	}
	return a.s<b.s;
}

unsigned sum(int a,int b)
{
	unsigned s=0;
	for(int i=a;i>0;i-=i&-i)
	{
		for(int j=b;j>0;j-=j&-j)
		{
			s=(s+c[i][j]);
		}
	}
	return s;
}

void add(int a,int b,long long x)
{
	for(int i=a;i<=n;i+=i&-i)
	{
		for(int j=b;j<=n;j+=j&-j)
		{
			c[i][j]=(c[i][j]+x);
		}
	}
}

int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		memset(c,0,sizeof(c));
		p.clear();

		cin>>n;

		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}

		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cur.x=i;
				cur.y=j;
				cur.s=a[i]+a[j];
				p.push_back(cur);
			}
		}

		sort(p.begin(),p.end(),cmp);

		int m=p.size();
		unsigned res=0;

		for(int i=0;i<m;i++)
		{
			int x=p[i].x;
			int y=p[i].y;
			unsigned v=sum(y-1,y-1)-sum(x,y-1)-sum(y-1,x)+sum(x,x);
			add(x,y,(v+1));
			res=(res+v+1);
		}

		printf("Case %d: %lld\n",z,res);
	}
	return 0;
}

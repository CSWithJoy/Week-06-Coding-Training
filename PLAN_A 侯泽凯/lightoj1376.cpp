//完全没有想到用树状数组 维护
//http://forty.sinaapp.com/?p=113
#include<bits/stdc++.h>
using namespace std;

//树状数组记录的是第s长度处比s小的线段和的个数
int bit[100005];
int a[105];

//向下求和
int sum(int i)
{
	int s = 0;
	while(i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

//向上更新
void add(int i)
{
	while(i<100001)
	{
		bit[i]+= 1;
		i += i & -i;
	}
}

int main()
{
    int t;
	cin>>t;

	for(int z=1;z<=t;z++)
	{
		memset(bit,0,sizeof(bit));

		int n;
		scanf("%d",&n);

		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
		}

		//最大边肯定是要小于其他五边之和
		//a+b+c<f-d-e
		sort(a,a+n);

		long long cnt1 = 0 , cnt2 = 0 , ans = 0;
		//ans ：种类数
		//cnt1、2：必定成立的后项和的个数（因为 0< f-d-e < 100000）
		for(int i = n - 1 ; i >= 0 ; i--)
		{
			//找<i的数（前三项）a,b,c
			//判断ans加什么
			for(int j = 0 ; j < i-1 ; j++)
			{
				for(int k = j + 1 ; k < i ; k++)
				{
					int s = a[i] + a[j] + a[k]-1;//离散化

					if(s<=100000)
						ans += sum(s);//在前一和的长度处求和加入ans
					else //s>100000
						ans += cnt1;

					//for内 始终执行
					ans += cnt2;
				}
			}
			//找>i的数（后三项）d,e,f
			//对ans加的项进行操作
			for(int j = i + 1 ; j < n - 1 ; j ++)
			{
				for(int k = j + 1 ; k <= n - 1 ; k++)
				{
					int s = a[k] - a[j] - a[i];//或（只可写一处离散）int s = a[k] - a[j] - a[i]+1;

					if(s<=0)
						cnt2++;
					else//s>0
					{
						add(s);//后一项的长度放入树状数组
						cnt1++;
					}
				}
			}
		}
		printf("Case %d: %lld\n",z,ans);
	}
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <stack>
using namespace std;
const int N=10000001;

int a[N],cnt;
int solve()
{
    stack<int>s;
    stack<int>sum;
    for(int i=0;i<cnt;i++)
    {
        if(a[i]<0)
        {
            if(s.size())
            {
                if(sum.top()<=fabs(a[i]))
                    return 0;
                int tmp = sum.top();
                tmp-=fabs(a[i]);
                sum.pop(); sum.push(tmp);
            }
            s.push(a[i]);
            sum.push(fabs(a[i]));
        }
        else
        {
            if(s.empty())
                return 0;
            if(fabs(s.top())!=a[i])
                return 0;
            s.pop();
            sum.pop();
        }
    }
    return 1;
}
int main()
{
    cnt = 0;
    int b;char c;
    while(scanf("%d%c",&b,&c)!=EOF)
    {
        a[cnt++]=b;
        if(c=='\n')
        {
            if(cnt%2==1)
                printf(":-( Try again.\n");
            else
            {
                int flag=solve();
                if(flag)
                    printf(":-) Matrioshka!\n");
                else
                    printf(":-( Try again.\n");
            }
            cnt = 0;
        }
    }

    return 0;
}

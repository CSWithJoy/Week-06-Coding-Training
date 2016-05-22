#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long LL;
const int N = 10000;
mat mul(mat a,mat b)
{
    mat c(a.size(),vec(b[0].size()));
    for(int i=0;i<a.size();i++)
    {
        for(int k=0;k<b.size();k++)
        {
            for(int j=0;j<b[0].size();j++)
                c[i][j] = (c[i][j]+a[i][k]*b[k][j])%N;
        }
    }
    return c;
}

mat solve_pow(mat a,int n) //¿ìËÙÃÝ
{
    mat b(a.size(),vec(a.size()));
    for(int i=0;i<a.size();i++)
        b[i][i]=1;
    while(n>0)
    {
        if(n & 1)
            b=mul(b,a);
        a=mul(a,a);
        n >>= 1;
    }

    return b;
}
LL n;
int main()
{
     mat a(2,vec(2));
    while(scanf("%lld",&n)!=EOF)
    {
       // cout<<n<<endl;
        if(n==-1) break;
        a[0][0]=1,a[0][1]=1;
        a[1][0]=1,a[1][1]=0;
        a=solve_pow(a,n);
        printf("%d\n",a[1][0]);
    }
    return 0;
}

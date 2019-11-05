#include<bits/stdc++.h>
using namespace std;
//在进入函数前，使a < m
//递归写法
long long binaryPow(long long a, long long b, long long m)
{
    if(b == 0)
        return 1;
    if(b%2)
        return a*binaryPow(a, b-1, m)%m;
    else
    {
        long long mul = binaryPow(a, b/2, m);
        return mul*mul%m;
    }
}
//迭代写法
long long binaryPow2(long long a, long long b, long long m)
{
    long long ans = 1;
    while(b)
    {
        if(b & 1)
        {
            ans = ans*a%m;
        }
        a = a*a%m;
        b >>= 1;
    }
    return ans;
}
int main()
{
    long long b, p, k, s;
    scanf("%lld%lld%lld",&b,&p,&k);
    if(k == 1)              //任何正整数mod 1 == 0
        s = 0;
    else
        s = binaryPow(b%k,p,k);
    printf("%lld^%lld mod %lld=%lld",b,p,k,s);//2^10 mod 9=7
    return 0;
}

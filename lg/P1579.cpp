#include<bits/stdc++.h>
#define MAXN 20000
using namespace std;
int p[MAXN];
int sieveofe()
{
    memset(p, 1, sizeof(int)*MAXN);
    int i, j;

    p[0] = 0;
    p[1] = 0;
    p[2] = 1;
    // 初始化

    for(i = 3; i <= MAXN; i++)
	{
        p[i++] = 1;
        p[i] = 0;
    }
    //除了2，其余偶数都是合数，先去除偶数

    int _max = sqrt(MAXN);
    for(i = 3; i <= _max; i++)     //只需要判断到sqrt(MAXN)
	{
        if(p[i])
		{
            for(j = i * i; j < MAXN; j += i)
                p[j] = 0;
   //进行筛选，从i*i开始，如对素数3，从3*3开始，不需要从3*2开始，因为对素数2，2*3已经筛去
        }
    }
}
int main()
{
    sieveofe();
    int n = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(p[i] && p[j] && p[n-i-j] && n-i-j > 1)
            {
                printf("%d %d %d",i,j,n-i-j);
                return 0;
            }
        }
    }
}

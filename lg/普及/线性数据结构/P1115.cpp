#include<bits/stdc++.h>
#define min_ -10000
using namespace std;
int s[200001];
int main()
{
    int n, begin_n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&s[i]);
    }
    int nowmax = min_, maxmax = min_;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += s[i];
        if(sum > nowmax)
        {
            nowmax = sum;
        }
        if(sum < 0)
        {
            sum = 0;
        }
        if(maxmax < nowmax)
        {
            maxmax = nowmax;
        }
    }
    printf("%d",maxmax);
    return 0;
}

#include<cstdio>
#define MAXN 1000000
long long int a[MAXN] = {0};
int main()
{
    int n;
    int day = 1;
    int max_day = 1;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&a[i]);
        if(i > 0 && a[i] > a[i-1])
        {
            day++;
            if(day > max_day)
                max_day = day;
        }
        else
            day = 1;
    }
    printf("%d",max_day);
    return 0;
}

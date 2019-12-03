#include<cstdio>
int main()
{
    int i = 0;
    long long int a[101] = {0};
    for(i = 0; ;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i] == 0)
            break;
    }
    for(int j = i-1; j >= 0; j--)
    {
        printf("%d ",a[j]);
    }
    return 0;
}

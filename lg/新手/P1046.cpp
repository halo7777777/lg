#include<cstdio>
int main()
{
    int n = 0;
    int a[10] = {0};
    int b = 0;
    for(int i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&b);
    for(int i = 0; i < 10; i++)
    {
        if(30 + b >= a[i])
            n++;
    }
    printf("%d",n);
    return 0;
}

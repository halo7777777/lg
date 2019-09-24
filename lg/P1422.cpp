#include<cstdio>
int main()
{
    int n = 0;
    double cost = 0;
    scanf("%d",&n);
    if(n <= 150)
        cost = 0.4463*n;
    else if(n <= 400)
        cost = 150*0.4463 + 0.4663*(n - 150);
    else
        cost = 150*0.4463 + 0.4663*250 + 0.5663*(n-400);
    printf("%.1f",cost);
    return 0;
}

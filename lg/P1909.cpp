#include<cstdio>
#include<cmath>
int main()
{
    int need = 0;
    int s[2] = {0};
    int cost = 0;
    int cost_min = 10000000;
    scanf("%d",&need);
    for(int i = 0; i < 3; i++)
    {
        scanf("%d%d",&s[0],&s[1]);
        cost = ceil((double)need/s[0]) * s[1];
        if(cost_min > cost)
            cost_min = cost;
    }
    printf("%d",cost_min);
    return 0;
}

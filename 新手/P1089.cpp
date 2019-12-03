#include<cstdio>
#include<cmath>
int main()
{
    int left = 0;
    int money = 0;
    int deposit = 0;
    int flag = 1;
    for(int i = 0; i < 12; i++)
    {
        scanf("%d",&money);
        left += 300 - money;
        deposit += left/100;
        left = left%100;
        if(left < 0)
        {
            printf("-%d",i+1);
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("%d",(left+120*deposit));
    return 0;
}

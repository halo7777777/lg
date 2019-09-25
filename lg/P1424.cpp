#include<cstdio>
int main()
{
    int x, n;
    scanf("%d%d",&x,&n);
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        if((x+i)%7 != 6 && (x+i)%7 != 0)
            s += 250;
    }
    printf("%d",s);
    return 0;
}

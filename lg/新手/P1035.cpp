#include<cstdio>
int main()
{
    double s = 0;
    int k = 0;
    scanf("%d",&k);
    for(int i = 1; ; i++)
    {
        s += 1/(double)i;
        if(s > k)
        {
            printf("%d",i);
            return 0;
        }
    }
}

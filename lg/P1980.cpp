#include<cstdio>
int main()
{
    int x;
    long long int n;
    int steps  = 0;
    int fq = 0;
    scanf("%lld%d",&n,&x);
    long long int cpy_n = n;
    for(; n > 0; )
    {
        n /= 10;
        steps++;
    }
    for(int i = 1; i <= cpy_n; i++)
    {
        int cpy_i = i;
        for(int j = 0; j < steps && cpy_i > 0; j++)
        {
            if(x == cpy_i%10)
            {
                fq++;
            }
            cpy_i /= 10;
        }
    }
    printf("%d",fq);
    return 0;
}

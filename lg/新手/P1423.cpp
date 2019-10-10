#include<cstdio>
int main()
{
    double s;
    double my_s = 0;
    double a = 2;
    scanf("%lf",&s);
    for(int i = 1; ; i++)
    {
        my_s += a;
        a *= 0.98;
        if(my_s >= s)
        {
            printf("%d",i);
            return 0;
        }
    }
}

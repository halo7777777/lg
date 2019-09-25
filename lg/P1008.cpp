#include<cstdio>
int main()
{
    for(int i = 123; i < 333; i++)
    {
        int count_ = 0;
        int a[10] = {0};
        a[i%10] = a[i/10%10] = a[i/100] = a[i*2%10] = a[i*2/10%10] = a[i*2/100] = a[i*3%10] = a[i*3/10%10] = a[i*3/100] = 1;
        for(int j = 1; j < 10; j++)
        {
            if(a[j] == 1)
                count_++;
        }
        if(count_ == 9)
        {
            printf("%d %d %d\n",i,2*i,3*i);
        }
    }
    return 0;
}


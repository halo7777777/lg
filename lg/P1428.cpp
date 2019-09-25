#include<cstdio>
#define MAXSIZE 1000
int main()
{
    int n;
    int a[MAXSIZE] = {0};
    int b[MAXSIZE] = {0};
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        for(int j = i; j >= 0; j--)
        {
            if(a[i] > a[j])
                b[i]++;
        }
        printf("%d ",b[i]);
    }
    return 0;
}

#include<cstdio>
#define MAXSIZE 10002
int main()
{
    int a[MAXSIZE] = {0};
    int l, m;
    int bk_l = 0;
    scanf("%d%d",&l,&m);
    for(int i = 0; i < m; i++)
    {
        int j,k;
        scanf("%d%d",&j,&k);
        for(;j <= k; j++)
        {
            a[j] = 1;
        }
    }
    for(int i = 0; i <= l; i++)
    {
        if(a[i] == 0)
            bk_l++;
    }
    printf("%d",bk_l);
    return 0;
}

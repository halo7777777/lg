//暴力递归仅限于500内，本题会超时
/*
#include<cstdio>
int cnt = 1;
int find_num(int n)
{
    if(n == 1)
    {
        return 0;
    }
    for(int i = 1; i <= n/2; i++)
    {
        cnt++;
        find_num(i);
    }

}
int main()
{
    int n = 0;
    scanf("%d",&n);
    find_num(n);
    printf("%d",cnt);
    return 0;
}
*/
#include<cstdio>
int main()
{
    int n, cnt = 1, i, f[1010];
    f[0] = f[1] = 1;
    scanf("%d", &n);
    for(i = 2; i <= n; i++)
    {
        if(i%2 == 0)
        {
            f[i] = f[i-1] + f[i/2];
        }
        else
        {
            f[i] = f[i-1];
        }
    }
    printf("%d", f[n]);
}

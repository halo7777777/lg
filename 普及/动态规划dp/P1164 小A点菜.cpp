#include<bits/stdc++.h>
using namespace std;
//错误
/*
int f[MAXN] = {0};
int a[MAXN] = {0};
int used[MAXN][1001] = {0};
int main()
{
    int N, M;
    scanf("%d%d",&N,&M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d",&a[i]);
    }
    f[0] = 1;
    for(int m = 1; m <= M; m++)
    {
        for(int i = 0; i < N; i++)
        {
            if((m-a[i]) >= 0 && !used[m-a[i]][i])
            {   if(m==2)
                printf("i = %d\n",i);
                f[m] += f[m-a[i]];
                used[m][i] = 1;
            }
        }
    }
    printf("%d\n",f[2]);
    printf("%d",f[M]);
    return 0;
}
*/
int a[101] = {0};
int f[10001]={0};
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    f[0] = 1;     //钱刚好够时的数量
    for(int i = 1; i <= n; ++i)
        for(int j = m; j >= a[i]; j--)
        {
            f[j] = f[j]+f[j-a[i]];      //吃这道菜
        }
    cout << f[m];
    return 0;
}

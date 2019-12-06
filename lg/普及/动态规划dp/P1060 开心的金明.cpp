#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
int f[MAXN] = {0};
int a[MAXN][2] = {0};
int main()
{
    int N, m;
    scanf("%d%d",&N,&m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    for(int i = 0; i < m; i++)
    {
        for(int n = N; n >= a[i][0]; n--)
        {
            f[n] = max(f[n],f[n-a[i][0]]+a[i][0]*a[i][1]);
        }
    }
    int ans = f[N];
    printf("%d",ans);
    return 0;
}

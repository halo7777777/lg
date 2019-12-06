#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
int w, n;
int g[MAXN];
int ans = 0;
int main()
{
    scanf("%d%d",&w,&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&g[i]);
    }
    sort(g,g+n);
    int r = n-1;
    int f = 0;
    for(; r >= f; )
    {
        if(r == f)
        {
            ans++;
            r--;
            f++;
        }
        else if(g[f]+g[r] > w)
        {
            r--;
            ans++;
        }
        else
        {
            r--;
            f++;
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}

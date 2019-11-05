#include<bits/stdc++.h>
#define MAXN 100
using namespace std;
bool a[MAXN];
int main()
{
    memset(a,0,sizeof(a));
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < k; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        a[tmp] = 1;
    }
    int time = 0;
    for(int i = 0; i < n; time++)
    {
        if(a[i] == 1)
            m++;
        i += m;
    }
    printf("%d",time);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int flag[3][1000] = {0};
int ansq[100], ans = 0;
int n = 0;
void DFS(int i)
{
    if(i > n)
    {
        ++ans;
        if(ans > 3)
            return;
        for(int i = 1; i <= n; i++)
            printf("%d ",ansq[i]);
        printf("\n");
        return;
    }
    for(int j = 1; j <= n; j++)
    {
        if(!flag[0][j] && !flag[1][j+i] && !flag[2][i-j+n])
        {
            ansq[i] = j;
            flag[0][j] = 1;
            flag[1][j+i] = 1;
            flag[2][i-j+n] = 1;
            DFS(i+1);
            flag[0][j] = 0;
            flag[1][j+i] = 0;
            flag[2][i-j+n] = 0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    DFS(1);
    printf("%d",ans);
    return 0;
}

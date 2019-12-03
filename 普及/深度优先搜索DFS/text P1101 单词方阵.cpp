#include<bits/stdc++.h>
using namespace std;
const int maxn = 100+10;
struct node
{
    int x,y;
}c[maxn];    //保存符合的点的位置
int flag[maxn][maxn] = {0};
char a[maxn][maxn], model[] = "yizhong";
int dir[][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int n;
void DFS(int x, int y, node *c, int k, int cur)
{
    if(cur == 7)
    {
        for(int i = 0; i < 7; i++)
            flag[c[i].x][c[i].y] = 1;
            return;
    }
    int dx = x+dir[k][0];
    int dy = y+dir[k][1];
    if(cur == 6 || a[dx][dy] == model[cur+1])
    {
        c[cur].x = x;
        c[cur].y = y;
        DFS(dx, dy, c, k, cur+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
       scanf("%s",a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 'y')
                for(int k = 0; k < 8; k++)
                {
                    int x = i+dir[k][0];
                    int y = j+dir[k][1];
                    if(a[x][y] == 'i')
                        DFS(i,j,c,k,0);
                }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(flag[i][j])
                printf("%c",a[i][j]);
            else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}

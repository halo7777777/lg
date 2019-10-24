#include<bits/stdc++.h>
using namespace std;
int n, m, t;
int sx, sy, fx, fy;
int temp_x, temp_y;
int cnt = 0;
int flag[10][10] = {0};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void DFS(int nowx, int nowy)
{
    if(nowx <= 0 || nowy <= 0 || nowx > n ||nowy > m)
    {
        return;
    }
    if(nowx == fx && nowy == fy)
    {
        cnt++;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int x = nowx + dx[i];
        int y = nowy + dy[i];
        if(flag[x][y] == 2)
            continue;
        if(!flag[x][y])
        {
            flag[x][y] = 1;
            DFS(x,y);
            flag[x][y] = 0;
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    for(int i = 0; i < t; i++)
    {
        scanf("%d%d",&temp_x,&temp_y);
        flag[temp_x][temp_y] = 2;
    }
    flag[sx][sy] = 2;
    DFS(sx,sy);
    printf("%d\n",cnt);
    return 0;
}

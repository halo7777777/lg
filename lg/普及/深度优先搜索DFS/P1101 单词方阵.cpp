#include<bits/stdc++.h>
using namespace std;
int flag[100][100] = {0};
char a[100][100];
int n;
void DFS(int i, int j)
{

}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%c",&a[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 'y')
                DFS(i,j);
        }
    }
    return 0;
}

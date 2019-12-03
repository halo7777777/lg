#include<cstdio>
#include<cstdlib>
int un[5][3];
int main()
{
    int n, M;
    int ans = 0;
    scanf("%d%d",&n,&M);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d",&un[i][0],&un[i][1],&un[i][2]);
    }
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            int tmp = 9 ^ abs(un[0][0] - i) ^ abs(un[0][1] - j);
            int z1 = tmp + un[0][2], z2 = un[0][2] - tmp;
            if(z1 < 1 || z1 > M) z1 = -1;
            if(z2 < 1 || z2 > M) z2 = -1;
            for(int k = 1; k < n; k++)
            {
                tmp = 9 ^ abs(un[k][0] - i) ^ abs(un[k][1] - j);
                if(abs(un[k][2] - z1) != tmp) z1 = -1;
                if(abs(un[k][2] - z2) != tmp) z2 = -1;
            }
            if(~z2) ++ans;            //~按位取反 ~-1 = 0
            if(~z1 && z1 != z2) ++ans;
        }
    }
    printf("%d",ans);
    return 0;
}

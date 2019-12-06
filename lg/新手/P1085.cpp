#include<cstdio>
int main()
{
    int n[7][2] = {0};
    int most_i = 0;
    int most = 0;
    for(int i = 0; i < 7; i++)
    {
        scanf("%d%d",&n[i][0],&n[i][1]);
        if(n[i][0]+n[i][1] > most && n[i][0]+n[i][1] > 8)
        {
            most = n[i][0]+n[i][1];
            most_i = i + 1;
        }
    }
    printf("%d",most_i);
    return 0;
}

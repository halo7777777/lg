//时间复杂度为O（n^3），需要改进
//也可以用桶概念
#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int main()
{
    int n;
    int a[MAXN] = {0};
    int use[MAXN] = {0};
    int cmp = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                if(a[i] + a[j] == a[k] && use[k] == 0)
                {
                    cmp++;
                    use[k] = 1;
                }
            }
        }
    }
    printf("%d",cmp);
    return 0;
}

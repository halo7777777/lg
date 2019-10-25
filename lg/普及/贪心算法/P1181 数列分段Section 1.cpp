#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, ans = 0;
    int a[100001] = {0};
    int sum = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
        if(sum > m)
        {
            ans++;
            sum = a[i];
        }
    }
    ans++;
    printf("%d",ans);
    return 0;
}

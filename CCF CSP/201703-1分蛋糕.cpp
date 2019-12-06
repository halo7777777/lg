#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
    int ans = 0;
    int sum = 0;
    int n, k;
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
        if(sum >= k)
        {
            ans++;
            sum = 0;
        }
    }
    if(sum)
        ans++;
    printf("%d",ans);
    return 0;
}

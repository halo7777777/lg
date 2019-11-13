#include<bits/stdc++.h>
using namespace std;
/*1.DFS超时
long long ans = 0;
void func(int n, int k)
{
    if(n <= 0)
    {
        ans++;
        return;
    }
    for(int i = 1; i <= k; i++)
    {
        if(n-i < 0)
            break;
        func(n-i,k);
    }
}
int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    func(n,k);
    printf("%lld",ans%100003);
    return 0;
}
*/

// 2.dp   o（nk）
int n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int f[n+1];
    for(int i = 2; i <= n; i++)
        f[i] = 0;
    f[1] = f[0] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = min(i,k); j >= 1; j--)
        {
            f[i] += f[i-j];
            if(f[i] >= 100003)
                f[i] %= 100003;
        }
    }
    cout << f[n];
    return 0;
}


// 3.o(n)
// 4.树状数组

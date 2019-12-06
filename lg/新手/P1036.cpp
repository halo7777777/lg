#include<bits/stdc++.h>
using namespace std;
int x[30] = {0};
int is_prime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
int sum(int n, int k, int start, int now_sum)
{
    int cnt = 0;
    if(k == 0)
        return is_prime(now_sum);
    for(int i = start; i < n; i++)
    {
        cnt += sum(n,k-1,i+1,now_sum+x[i]);
    }
    return cnt;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&x[i]);
    }
    printf("%d",sum(n,k,0,0));
    return 0;
}

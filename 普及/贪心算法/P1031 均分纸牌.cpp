#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;
int n;
int A[MAXN];
int ans = 0;
int sum = 0, ave;


int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
        sum += A[i];
    }
    ave = sum/n;
    for(int i = 0; i < n; i++)
    {
        if(A[i] > ave)
        {
            A[i+1] += A[i]-ave;
            ans++;
        }
        else if(A[i] < ave)
        {
            A[i+1] -= ave-A[i];
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}

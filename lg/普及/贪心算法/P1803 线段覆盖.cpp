#include<bits/stdc++.h>
#define MAXN 1000001
using namespace std;
struct node{
    int ai;
    int bi;
};
node test[MAXN];
bool cmp(node a, node b)
{
    if(a.bi == b.bi)
        return a.ai > b.ai;
    else
        return a.bi < b.bi;
}
int ans = 0;
int n;
int t_end = 0;
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&test[i].ai,&test[i].bi);
    }
    sort(test,test+n,cmp);
    for(int i = 0; i < n; i++)
    {
        if(test[i].ai >= t_end)
        {
            t_end = test[i].bi;
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}

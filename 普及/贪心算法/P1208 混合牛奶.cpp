#include<bits/stdc++.h>
using namespace std;
#define MAXN 10001
int n, m;
int cost = 0, amount = 0;
struct node{
    int pi;
    int ai;
};
struct node milk[MAXN];

bool cmp(node a, node b)
{
    return a.pi < b.pi;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d",&milk[i].pi, &milk[i].ai);
    }
    sort(milk,milk+m,cmp);
    for(int i = 0; ; i++)
    {
        if(amount + milk[i].ai < n)
        {
            amount += milk[i].ai;
            cost += milk[i].ai * milk[i].pi;
        }
        else
        {
            cost  += (n - amount)*milk[i].pi;
            break;
        }
    }
    printf("%d",cost);
    return 0;
}

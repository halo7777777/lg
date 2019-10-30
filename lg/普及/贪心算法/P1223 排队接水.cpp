#include<bits/stdc++.h>
using namespace std;
#define MAXN 10001
struct node{
    double time;
    int num;
};
bool cmp(node a, node b)
{
    return a.time < b.time;
}
node a[MAXN];
double sum = 0;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf",&a[i].time);
        a[i].num = i+1;
    }
    sort(a,a+n,cmp);
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i].num);
        sum += a[i].time*(n-i-1);
    }
    printf("\n%.2f",sum/n);
    return 0;
}

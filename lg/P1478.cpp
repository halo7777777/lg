#include<bits/stdc++.h>
#define MAXN 10000
using namespace std;
struct apple{
    int x;
    int y;
};
bool cmp(apple a, apple b)
{
    return a.y < b.y;
}
int main()
{
    int n, s;
    scanf("%d %d",&n, &s);
    int a, b;
    scanf("%d %d",&a, &b);
    struct apple l[MAXN];
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d",&(l[i].x),&(l[i].y));
    }
    sort(l,l+n,cmp);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(a+b >= l[i].x  && s >= l[i].y)
        {
            cnt++;
            s -= l[i].y;
        }
    }
    printf("%d",cnt);
    return 0;
}

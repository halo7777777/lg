//EEROR

/*
#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
    int n;
    int a;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a);
        q.push(a);
    }
    long long sum = q.top(),cost = 0;
    q.pop();
    while(!q.empty())
    {
        sum += q.top();
        cost += sum;
        q.pop();
    }
    printf("%lld",cost);
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x,q.push(x);
    while(q.size() >= 2)            //在每次求和得最小堆以后都要再输入队列进行判断
    {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        ans += a+b;
        q.push(a+b);
    }
    cout << ans << endl;
    return 0;
}

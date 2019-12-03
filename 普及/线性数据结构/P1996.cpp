//队列方法
//遍历完一个数后，将其从队头pop出，再push进队尾，模拟循环队列
#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    int n, m, nowx = 1;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        q.push(i);
    while(!q.empty())
    {
        if(nowx == m)
        {
            printf("%d ",q.front());
            q.pop();
            nowx = 1;
        }
        else
        {
            q.push(q.front());
            q.pop();
            nowx++;
        }
    }
    return 0;
}

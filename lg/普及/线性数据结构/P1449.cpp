#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<char> q;
    stack<int> s;
    int num1, num2;
    char a;
    while(scanf("%c",&a) && a != '@')
    {
            q.push(a);
    }
    while(!q.empty())
    {
        int num = 0;
        while(q.front() >= '0' && q.front() <= '9')
        {
            num = 10*num + (q.front() - '0');
            q.pop();
            if(q.front() == '.')
            {
                q.pop();
                break;
            }
        }
        if(num)
            s.push(num);
        else
        {
            num2 = s.top();
            s.pop();
            num1 = s.top();
            s.pop();
            if(q.front() == '+')
                num1 = num1 + num2;
            else if(q.front() == '-')
                num1 = num1 - num2;
            else if(q.front() == '*')
                num1 = num1 * num2;
            else if(q.front() == '/')
                num1 = num1/num2;
            s.push(num1);
            q.pop();
        }
    }
    printf("%d",s.top());
    return 0;
}

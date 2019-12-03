#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> s;
    char c;
    int r = 0, l = 0;
    int flag = 0;
    while(scanf("%c",&c) && c != '@')
    {
        s.push(c);
    }
    while(!s.empty())
    {
        if(s.top() == '(' )
        {
            l++;
        }
        if(s.top() == ')')
        {
            r++;
        }
        s.pop();
        if(l > r)
        {
            printf("NO");
            return 0;
        }
    }
    if(l == r)
        printf("YES");
    else
        printf("NO");
    return 0;
}

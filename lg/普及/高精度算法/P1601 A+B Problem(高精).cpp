#include<bits/stdc++.h>
#define MAXN 1000
using namespace std;
struct bign{
    int d[MAXN];
    int len;
    bign()
    {
        memset(d,0,sizeof(d));
        len = 0;
    }
};
bign add(bign a, bign b)
{
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len || i < b.len; i++)
    {
        int temp = carry + a.d[i] + b.d[i];
        carry = temp/10;
        temp = temp%10;
        c.d[i] = temp;
        c.len++;
    }
    if(carry)
    {
        c.d[c.len++] = carry;
    }
    return c;
}
bign change(string a)    //倒着存
{
    bign c;
    c.len = a.length();
    for(int i = 0; i < a.length(); i++)
    {
        c.d[i] = a[a.length()-i-1] - '0';
    }
    return c;
}
int main()
{
    string a, b;
    bign c, d;
    cin >> a >> b;
    c = change(a);
    d = change(b);
    c = add(c,d);
    for(int i = 0; i < c.len; i++)
    {
        printf("%d",c.d[c.len-i-1]);
    }
    return 0;
}

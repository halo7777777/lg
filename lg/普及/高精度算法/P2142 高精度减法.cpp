#include<bits/stdc++.h>
#define MAXN 20000
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
bign change(string a)
{
    bign c;
    for(int i = 0; i < a.length(); i++)
    {
        c.d[i] = a[a.length()-i-1] - '0';
        c.len++;
    }
    return c;
}
int compare(bign a,bign b)
{
    if(a.len > b.len)
        return 1;
    else if(a.len < b.len)
        return -1;
    else
    {
        for(int i = 0; i < a.len; i++)
        {
            if(a.d[a.len-i-1] < b.d[a.len-i-1])
                return -1;
            else if(a.d[a.len-i-1] > b.d[a.len-i-1])
                return 1;
        }
        return 0;
    }
}
bign sub(bign a, bign b)
{
    bign c;
    for(int i = 0; i < a.len || i < b.len; i++)
    {
        if(a.d[i] < b.d[i])
        {
            a.d[i+1]--;
            a.d[i] = 10+a.d[i];
        }
        c.d[i] = a.d[i] - b.d[i];
        c.len++;
    }
    while(c.len-1 > 0 && !c.d[c.len-1])
    {
        c.len--;
    }
    return c;
}
int main()
{
    string a, b;
    cin >> a >> b;
    bign c, d;
    c = change(a);
    d = change(b);
    if(!compare(c,d))
    {
        printf("0");
        return 0;
    }
    else if(compare(c,d) == -1)
    {
        c = sub(d,c);
        printf("-");
    }
    else
    {
        c = sub(c,d);
    }
    for(int i = 0; i < c.len; i++)
    {
        printf("%d",c.d[c.len-i-1]);
    }
    return 0;
}

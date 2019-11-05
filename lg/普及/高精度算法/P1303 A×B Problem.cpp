//每个数字不超过10^2000
#include<bits/stdc++.h>
using namespace std;
struct bign{
    int d[50001];
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
    c.len = a.length();
    for(int i = 0; i < a.length(); i++)
    {
        c.d[i] = a[a.length()-i-1] - '0';    //倒着存
    }
    return c;
}
bign multi(bign a, bign b)
{
    bign c;
    c.len = a.len + b.len;       //先确定长度
    for(int i = 0; i < a.len; i++)
    {
        for(int j = 0; j < b.len; j++)
        {
            c.d[i+j] += a.d[i]*b.d[j];    //高精度乘法关键：位数相对
        }
    }
    for(int i = 0; i < c.len; i++)  //从低位到高位
    {
        if(c.d[i] > 9)     //进位
        {
            c.d[i+1] += c.d[i]/10;
            c.d[i] %= 10;
        }
    }
    while(c.len - 1 > 0 && !c.d[c.len-1])
    {
        c.len--;
    }
    return c;
}

int main()
{
    string a1, b1;
    bign a, b, c;

    cin >> a1 >> b1;
    a = change(a1);
    b = change(b1);
    c = multi(a,b);
    for (int i = c.len-1; i >= 0; i--)  //输出
        cout << c.d[i];
    return 0;
}

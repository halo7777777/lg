//本题要用高精度

#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
struct people{
    int right;
    int left;
};
struct money{                             //高精度

    int num[MAXN];
    int len;
    money()
    {
        memset(num,0,sizeof(num));
        len = 0;
    }
};
money multi(money a, int n)               //高精度乘低精度
{
    money c;
    int carry = 0;               //进位
    for(int i = 0; i < a.len; i++)
    {
        int temp = a.num[i] * n + carry;
        c.num[c.len++] = temp%10;        //个位作为该位结果
        carry = temp/10;
    }
    while(carry != 0)                  //乘法的进位可能不止一位
    {
        c.num[c.len++] = carry%10;
        carry /= 10;
    }
    return c;
}
money divide(money a,int n)               //高精度除以低精度
{
    money c;
    int r = 0;                      //余数
    c.len = a.len;             //被除数的每一位和商的每一位是一一对应的
    for(int i = a.len - 1; i >=0 ; i--)
    {
        r = r*10 + a.num[i];
        if(r < n)                 //不够除
            c.num[i] = 0;
        else                      //够除
        {
            c.num[i] = r/n;
            r = r%n;
        }
    }
    while(c.len - 1 >= 1 && c.num[c.len - 1] == 0)    //去除高位的0，同时至少保留一位最低位
    {
        c.len--;
    }
    return c;
}
bool cmp(people a, people b)                    //左右手乘积大的放后面
{
    return a.left*a.right < b.left*b.right;
}
people p[MAXN];
int n;
money maxn;

void my_max(money a)
{
    if(a.len > maxn.len)
    {
        maxn.len = a.len;
        for(int i = 0; i < a.len; i++)
            maxn.num[i] = a.num[i];
    }
    else if(a.len == maxn.len)
    {
        for(int i = a.len-1; i >= 0; i--)
        {
            if(maxn.num[i] < a.num[i])
            {
                for(int j = 0; j < a.len; j++)
                    maxn.num[j] = a.num[j];
                break;
            }
        }
    }
}


int main()
{
    money a;
    scanf("%d",&n);
    for(int i = 0; i < n+1; i++)
    {
        scanf("%d %d",&p[i].left,&p[i].right);
    }
    sort(p+1,p+n+1,cmp);          //达到了大臣钱最大值最小的排序
    a.num[0] = 1; a.len = 1;        //初始化乘法
    for(int i = 0; i < n; i++)     //计算每个大臣的钱，保存最大值
    {
        money c;
        a = multi(a,p[i].left);
        c = divide(a,p[i+1].right);
        my_max(c);                 //判断是否最大
    }
    for(int i = maxn.len - 1; i >= 0; i--)
    {
        printf("%d",maxn.num[i]);
    }
    return 0;
}

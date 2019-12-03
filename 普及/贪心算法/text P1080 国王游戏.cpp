//����Ҫ�ø߾���

#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
struct people{
    int right;
    int left;
};
struct money{                             //�߾���

    int num[MAXN];
    int len;
    money()
    {
        memset(num,0,sizeof(num));
        len = 0;
    }
};
money multi(money a, int n)               //�߾��ȳ˵;���
{
    money c;
    int carry = 0;               //��λ
    for(int i = 0; i < a.len; i++)
    {
        int temp = a.num[i] * n + carry;
        c.num[c.len++] = temp%10;        //��λ��Ϊ��λ���
        carry = temp/10;
    }
    while(carry != 0)                  //�˷��Ľ�λ���ܲ�ֹһλ
    {
        c.num[c.len++] = carry%10;
        carry /= 10;
    }
    return c;
}
money divide(money a,int n)               //�߾��ȳ��Ե;���
{
    money c;
    int r = 0;                      //����
    c.len = a.len;             //��������ÿһλ���̵�ÿһλ��һһ��Ӧ��
    for(int i = a.len - 1; i >=0 ; i--)
    {
        r = r*10 + a.num[i];
        if(r < n)                 //������
            c.num[i] = 0;
        else                      //����
        {
            c.num[i] = r/n;
            r = r%n;
        }
    }
    while(c.len - 1 >= 1 && c.num[c.len - 1] == 0)    //ȥ����λ��0��ͬʱ���ٱ���һλ���λ
    {
        c.len--;
    }
    return c;
}
bool cmp(people a, people b)                    //�����ֳ˻���ķź���
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
    sort(p+1,p+n+1,cmp);          //�ﵽ�˴�Ǯ���ֵ��С������
    a.num[0] = 1; a.len = 1;        //��ʼ���˷�
    for(int i = 0; i < n; i++)     //����ÿ���󳼵�Ǯ���������ֵ
    {
        money c;
        a = multi(a,p[i].left);
        c = divide(a,p[i+1].right);
        my_max(c);                 //�ж��Ƿ����
    }
    for(int i = maxn.len - 1; i >= 0; i--)
    {
        printf("%d",maxn.num[i]);
    }
    return 0;
}

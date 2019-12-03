#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int tree[500010],rank[500010],n;
//�������� ��ԭ����ͱ仯������鶼���±�1��ʼ
long long ans;
struct point
{
    int num,val;
}a[500010];
bool cmp(point q, point w)
{
    if(q.val == w.val)
        return q.num < w.num;
    return q.val < w.val;
}
void update(int p, int d)    //������������
{
    for(; p <= n; p += p&-p)
        tree[p] += d;
}
int getsum(int p)          //����������ǰp��ĺ�
{
    int sum = 0;
    for(; p; p-= p&-p)
        sum += tree[p];
    return sum;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].val);
        a[i].num = i;
    }
/*
��������ɢ�����Ƚ������������� 1 ~ n �ֱ��Ӧ
 n ������ʾ���ǵ���Դ�С
*/
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++)   //����ֵ�Ĵ�С�ź�����rank���飨�������ֵ��ԭ�±�Ϊ�±꣩
        rank[a[i].num] = i;
    for(int i = 1; i <= n; i++)   //������˳������������
    {
        update(rank[i], 1);
        ans += i-getsum(rank[i]);
    }
    printf("%lld", ans);
    return 0;
}

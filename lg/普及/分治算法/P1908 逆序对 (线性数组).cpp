#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int tree[500010],rank[500010],n;
//树形数组 的原数组和变化后的数组都从下标1开始
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
void update(int p, int d)    //更新树形数组
{
    for(; p <= n; p += p&-p)
        tree[p] += d;
}
int getsum(int p)          //求树形数组前p项的和
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
对数据离散化，先将数据排序，再用 1 ~ n 分别对应
 n 个数表示它们的相对大小
*/
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++)   //将数值的大小排号输入rank数组（以输入的值的原下标为下标）
        rank[a[i].num] = i;
    for(int i = 1; i <= n; i++)   //按输入顺序构造树形数组
    {
        update(rank[i], 1);
        ans += i-getsum(rank[i]);
    }
    printf("%lld", ans);
    return 0;
}

//可选可不选
/*
给定N个整数（可能有负数），从中选择K个数，
使得这K个数之和恰好等于一个给定的整数X；
如果有多种方案，选择它们中元素平方和最大的一个
*/
#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
//序列A中n个数选k个数使得和为x，最大平方和为maxSumSqu
int n, k, x, maxSumSqu = -1, A[maxn];
//temp存放临时方案，ans存放平方和最大的方案
vector<int> temp, ans;
//当前处理index号整数， 当前已选整数个数为nowK
//当前已选整数之和为sum， 当前已选整数平方和为sumSqu
void DFS(int index, int nowK, int sum, int sumSqu)
{
    if(nowK == k && sum == x)
    {
        if(sumSqu > maxSumSqu)
        {
            maxSumSqu = sumSqu;    //更新最大平方和
            ans = temp;        //更新最优方案，vector可直接赋值
        }
        return;
    }
    //已经处理完n个数，或者超过k个数，或者和超过x，返回
    if(index == n || nowK > k || sum > x) return;
    temp.push_back(A[index]);   //选index号数
    DFS(index + 1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
    temp.pop_back();      //不选index号数
    DFS(index + 1, nowK, sum, sumSqu);
}
int main()
{
    scanf("%d%d%d",&n,&k,&x);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    DFS(0,0,0,0);
    printf("maxsum = %d\n",maxSumSqu);
    printf("Squ = ");
    for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        printf("%d ", *it);
    }
    return 0;
}

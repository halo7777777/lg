//递归从n中选一个，遍历左右子树到全部选完，sum算分数
//递归构造树
//怎么边计算分边构造？要再遍历一遍吗
#include<bits/stdc++.h>
using namespace std;
struct node{
    int score;
    int lchild;
    int rchild;
    int no;                 //记录这个结点在中序结点中的顺序
};
struct node tree[50] = {0};   //存输入的树结构体
bool flag_node[50] = {0};      //记录输入结点使用记录
int n;
long long max_ans = 0;
long long ans = 0;
int root = 0;            //记录根结点在输入中是第几号
//index记录已选用结点数

void DFS(int index, node father, ans)          //找出分数最高的中序序列
{
    if(index == n)
    {
        if(ans > max_ans)
        {
            max_ans = ans;
        }
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!flag_node[i])
        {
            father.lchild = i;
            flag_node[i] = true;
            DFS(index++, tree[i]);
            father.lchild = -1;
            father.rchild = i;
            DFS(index++, tree[i]);
            father.rchild = -1;
        }
    }
}
void output()         //将前序序列输出
{

}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",tree[i].score);
        tree[i].lchild = -1;
        tree[i].rchild = -1;
    }
    for(int i = 0; i < n; i++)
    {
        root = i;
        flag_node[i] = true;
        DFS(1, tree[i], tree[i].score);
    }
    return 0;
}

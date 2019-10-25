#include<bits/stdc++.h>
using namespace std;
struct node{
    int score;
    int lchild;
    int rchild;
    int mid;
    int pre;
};
struct node tree[50] = {0};
int n;
long long tmp_ans = 0;
long long ans = 0;

void DFS()
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
    DFS();
    return 0;
}

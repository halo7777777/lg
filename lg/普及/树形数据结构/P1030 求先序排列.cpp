#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
typedef struct Binode{
    char data;
    struct Binode *lchild, *rchild;
    Binode()
    {
        lchild = rchild = NULL;
    }
}Binode, *Bitree;

char in[MAXN];
char pos[MAXN];
void create(Bitree &T, int posL, int posR, int inL, int inR)
{
    if(posL > posR)
        return;
    T = new Binode;
    T->data = pos[posR];
    int k;
    for(k = inL; k <= inR; k++)
    {
        if(in[k] == pos[posR])
        {
            break;
        }
    }
    int numLeft = k - inL;     //算出左子树的结点个数，用于后序序列递归使用
    create(T->lchild, posL, posL+numLeft-1,inL, k-1);
    create(T->rchild, posL+numLeft, posR-1, k+1, inR);
}
void pretravel(Bitree &T)
{
    if(T == NULL)
        return;
    printf("%c",T->data);
    pretravel(T->lchild);
    pretravel(T->rchild);
}
int main()
{
    cin >> in;
    cin >> pos;
    Bitree T = NULL;
    int len = strlen(in);
    create(T,0,len-1,0,len-1);
    pretravel(T);
    return 0;
}

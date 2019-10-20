#include<bits/stdc++.h>
using namespace std;
//数组实现的静态链表
//用数组标号代表学生标号
#define MAXN 100005
typedef struct node* linklist;
struct node{
    int prior;
    int next;
};
int main()
{
    linklist s = new struct node [MAXN];
    memset(s,0,sizeof(s));
    int n, m, k, p, first;
    scanf("%d",&n);
    (s+1)->prior = 1;
    (s+1)->next = 1;
    first = 1;
    for(int i = 2; i <= n; i++)
    {
        scanf("%d%d",&k,&p);
        if(p == 1)
        {
            s[i].next = s[k].next;
            s[s[k].next].prior = i;
            s[k].next = i;
            s[i].prior = k;
        }
        else if(p == 0)
        {
            s[s[k].prior].next = i;
            s[i].prior = s[k].prior;
            s[i].next = k;
            s[k].prior = i;
            if(k == first)
                first = i;
        }
    }
    int x = 0;
    scanf("%d",&m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        if(s[x].next && s[x].prior)  ////记得使用后的指针置0，且不重复删除
        {
            s[s[x].prior].next = s[x].next;
            s[s[x].next].prior = s[x].prior;
            s[x].next = 0;
            s[x].prior = 0;
        }
        if(x == first)
        {
            first = s[x].next;
        }
    }
    for(int i = first, j = 0; ;j++)
    {
        if(s[i].next != first)
            printf("%d ",i);
        else
            printf("%d\n",i);
        i = s[i].next;
        if(i == first && j != 0)
        {
            break;
        }
    }
    return 0;
}
//用STL queue会TLE
/*
int main()
{
    queue<int> a;
    queue<int> b;
    int n, k, p;
    scanf("%d",&n);
    a.push(1);
    for(int i = 2; i <= n; i++)
    {
        scanf("%d%d",&k,&p);
        while(a.front() != k)
        {
            b.push(a.front());
            a.pop();
        }
        if(p == 1)
        {
            b.push(a.front());
            a.pop();
        }
        b.push(i);
        while(!a.empty())
        {
            b.push(a.front());
            a.pop();
        }
        while(!b.empty())
        {
            a.push(b.front());
            b.pop();
        }
    }
    int m;
    scanf("%d",&m);
    int x = 0,temp = 0;
    for(int i = 0 ;i < m && scanf("%d",&x) && x != temp; i++)
    {
        temp = x;
        while(!a.empty())
        {
            if(a.front() != x)
            {
                b.push(a.front());
            }
            a.pop();
        }
        while(!b.empty())
        {
            a.push(b.front());
            b.pop();
        }
    }
    while(!a.empty())
    {
       printf("%d ",a.front());
        a.pop();
    }
    return 0;
}
*/
//普通链表TLE
/*
typedef struct node *linklist;
struct node{
    int data;
    linklist next;
};
int main()
{
    int n, k, p, m;
    scanf("%d",&n);
    linklist l = (linklist)new struct node;
    linklist pl = (linklist)new struct node;
    pl->next = l->next = NULL;
    l->next = pl;
    pl->data = 1;
    linklist pre = l;
    for(int i = 2; i <= n; i++)
    {
        linklist temp = (linklist)new struct node;
        pl = l->next;
        scanf("%d%d",&k,&p);
        while(pl)
        {
            if(pl->data == k)
            {
                linklist temp = (linklist)new struct node;
                temp->data = i;
                temp->next = NULL;
                if(p == 0)
                {
                    temp->next = pl;
                    pre->next = temp;
                }
                else if(p == 1)
                {
                    temp->next = pl->next;
                    pl->next = temp;
                }
            }
            pre = pl;
            pl = pl->next;
        }
    }
    scanf("%d",&m);
    int x;
    pre = l;
    linklist tmp = pl;
    for(int i = 0; i < m; i++)
    {
        pl = l->next;
        scanf("%d",&x);
        while(pl)
        {
            if(pl->data == x)
            {
                tmp = pl;
                pre->next = pl->next;
                delete tmp;
            }
            pre = pl;
            pl = pl->next;
        }
    }
    pl = l->next;
    while(pl)
    {
        printf("%d ",pl->data);
        pl = pl->next;
    }
    return 0;
}
*/


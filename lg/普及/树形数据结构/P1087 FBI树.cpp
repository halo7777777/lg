#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
char s[MAXN];
int n;
typedef struct Binode{
    char data;
    struct Binode* lchild, *rchild;
}Binode, *Bitree;
char def(char *s)
{
    int l = strlen(s);
    int sum = 0;
    for(int i = 0; i < l; i++)
    {
        sum += s[i]-'0';
    }
    if(sum == 0)
        return 'B';
    else if(sum == l)
        return 'I';
    else
        return 'F';
}
void create(Bitree &T,char *s)
{
    int len = strlen(s);

    T = new Binode;
    T->data = def(s);
    if(len == 1)
    {
        T->lchild = NULL;
        T->rchild = NULL;
        return;
    }

    char* temps = new char[10000];
    strcpy(temps,s);
    temps[len/2] = '\0';

    s = s+len/2;

//    printf("l = %s\n",temps);
 //   printf("r = %s\n",s);
   // system("pause");
    create(T->lchild,temps);
    create(T->rchild,s);
    delete temps;
}
void postravel(Bitree &T)
{
    if(T == NULL)
        return;
    postravel(T->lchild);
    postravel(T->rchild);
    printf("%c",T->data);
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    Bitree T = NULL;
    create(T,s);
    postravel(T);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
//STATIC LINKLIST
typedef struct node{
    int prior;
    int next;
}node;
node a[10001];
int main()
{
    int n, m, first;
    scanf("%d%d",&n,&m);
    first = 1;
    a[1].prior = n;
    a[1].next = 2;
    a[n].prior = n-1;
    a[n].next = 1;
    for(int i = 2; i < n; i++)
    {
        a[i].prior = i-1;
        a[i].next = i+1;
    }
    for(int i = 0; i < m; i++)
    {
        int p, q;
        scanf("%d%d",&p,&q);
        a[a[p].next].prior = a[p].prior;
        a[a[p].prior].next = a[p].next;
        if(q > 0)
        {
            int temp = p;
            if(p == first)
                first = a[p].next;
            for(int j = 0; j < q; j++)
            {
                temp = a[temp].next;
            }
            a[a[temp].next].prior = p;
            a[p].next = a[temp].next;
            a[temp].next = p;
            a[p].prior = temp;
        }
        else if(q < 0)
        {
            q = -q;
            int temp = p;
            for(int j = 0; j < q; j++)
            {
                temp = a[temp].prior;
            }
            a[a[temp].prior].next = p;
            a[p].prior = a[temp].prior;
            a[temp].prior = p;
            a[p].next = temp;
            if(temp == first)
                first = p;
        }
    }
    for(int i = first; ; )
    {
        printf("%d ",i);
        i = a[i].next;
        if(i == first)
            break;
    }
    return 0;
}

/*
STL
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	list<int>l;//�洢ѧ�ŵ�����
	for(int i=0;i<N;++i)//������ѧ�ż���������
		l.push_back(i+1);
	while(M--)
    {
		int a,b;
		scanf("%d%d",&a,&b);//��ȡ�ƶ���ѧ�ţ����ƶ��ĳ���
		list<int>::iterator i=l.begin();
		while(*i!=a)//�����������Ҫ�ƶ���ѧ���������е�λ��
			++i;
		i = l.erase(i);//ɾ����Ԫ��
		while(b<0)
        {//�ҵ��ƶ����λ��
			--i;
			++b;
		}
		while(b>0)
		{
			++i;
			--b;
		}
		l.insert(i,a);//�����Ԫ��
	}
	for(list<int>::iterator i=l.begin();i!=l.end();++i)//�������
		printf("%d ",*i);
	return 0;
}
*/




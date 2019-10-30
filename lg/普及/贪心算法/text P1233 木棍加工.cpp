//dp做法？
//贪心做法，把能处理的先处理标记
#include<bits/stdc++.h>
#define MAXN 10001
using namespace std;
int n;
struct stick{
    int L;
    int W;
};
bool cmp1(stick a, stick b)
{
    if(a.L == b.L)
        return a.W > b.W;
    return a.L > b.L;
}

stick a[MAXN];
bool used[MAXN];
int ans = 0;
int temp_W = 0;

int main()
{

 //   freopen("testdata (1).in","r",stdin);         //重定向文件输入
    memset(used,0,sizeof(used));
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&a[i].L,&a[i].W);
    }

    for(int i = 0; i < n; i++)         //双重循环贪心遍历
    {
        if(!used[i])
        {
            temp_W = a[i].W;
            for(int j = i+1; j < n; j++)
            {
                if(a[j].W <= temp_W && !used[j])
                {
                    used[j] = 1;
                    temp_W = a[j].W;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}

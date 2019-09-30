#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    scanf("%d %d %d",&a,&b,&c);
    int i;
    int n[10] = {0};
    int flag = 0;
    for(i = (int)(ceil(100.0/a)); i <= (int)(floor(1000.0/c)); i++)
    {
        int sum = 0;
        memset(n,0,sizeof(int)*10);            //注意memset输入的数据
        n[a*i/100] = n[a*i%10] = n[a*i/10%10] = n[b*i/100] = n[b*i%10] = n[b*i/10%10] = n[c*i/100] = n[c*i%10] = n[c*i/10%10] = 1;
        for(int j = 1; j < 10; j++)
        {
            sum += n[j];
        }
        if(sum == 9)
        {
            flag = 1;
            printf("%d %d %d\n",a*i,b*i,c*i);
        }
    }
    if(flag == 0)
        printf("No!!!");
    return 0;
}

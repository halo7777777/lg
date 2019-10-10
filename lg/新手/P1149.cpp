//打表表示出到1000数所用的木棒
#include<bits/stdc++.h>
using namespace std;
int a[2001] = {6};
int c[10] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
    int n = 0;
    scanf("%d",&n);
    int cnt = 0;
    int i,j;
    for(i = 1; i <= 2000; i++)
    {
        j = i;
        while(j >= 1)                  //每个数所用的火柴棒
        {
            a[i] = a[i] + c[j%10];
            j = j/10;
        }
    }
    for(int i = 0; i <= 1000; i++)
    {
        for(j = 0; j <= 1000; j++)
        {
            if(a[i] + a[j] + a[i+j] + 4 == n)
                cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}



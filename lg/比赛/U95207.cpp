//P5650
#include<cstdio>
#include<cstring>
#define MAXN 1000001
char s[MAXN] = {0};
int ans = 0;
int now = 0;
int main()
{
    int flag = 1;
    gets(s);

    for(int i = 0; s[i]; i++)    //需要特判全为1
    {
        if(s[i] != '1')
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        ans = -1;
        printf("%d",ans);
        return 0;
    }

    for(int i = 0; s[i];i++)
    {
        if(s[i] == '0')
            now++;
        else if(s[i] == '1')
            now--;
        if(now > ans)
            ans = now;
        if(now < 0)
            now = 0;
    }
    printf("%d",ans);
    return 0;
}

#include<cstdio>
#define MAXN 20
int main()
{
    char s[MAXN];
    scanf("%s",s);
    int sum = 0;
    int flag = 1;
    for(int i = 0; i < 11; i++)
    {
        if(s[i] == '-')
            continue;
        else
        {
            sum += flag*(s[i]-'0');
            flag++;
        }
    }
    if(sum%11 == 10 && s[12] == 'X')
        printf("Right");
    else if(sum%11 == 10 && s[12] != 'X')
    {
        s[12] = 'X';
        printf("%s",s);
    }
    else if(sum%11 == s[12]-'0')
            printf("Right");
    else
    {
        s[12] = sum%11+'0';
        printf("%s",s);
    }
    return 0;
}

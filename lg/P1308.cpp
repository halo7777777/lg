//*************
#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
char word[100];
char s[MAXN];
int main()
{
    int flag = 0;
    int first = MAXN;
    int ffirst = MAXN;
    int cnt = 0;
    gets(word);
    gets(s);
    int wlength = strlen(word);
    int slength = strlen(s);
    for(int i = 0; s[i] != 0; i++)
    {
        for(int j = 0; word[j] != 0; j++)
        {
            if(s[i-1] != ' ' && i > 0 && flag == 0)      //��Ҫ�ж�������һ�����ʵĿ�ͷ �Ҳ�Ӱ�쵥�ʵ�2��3...����ĸ���ж�
                break;
            j += flag;
            if(s[i] == word[j] || abs(s[i] - word[j]) == 32)
            {
                flag++;
                if(j == 0)
                    first = i;
                break;
            }
            else
            {
                flag = 0;
                first = MAXN;
                break;
            }
        }
        if(flag == wlength && (s[i+1] == ' ' || s[i+1] == 0))
        {
            cnt++;
            ffirst = (ffirst < first)? ffirst:first;
            flag = 0;
        }
    }
    if(cnt)
        printf("%d %d",cnt,ffirst);
    else
        printf("-1");
    return 0;
}

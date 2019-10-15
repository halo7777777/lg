//KMP算法，统计pattern在text中出现的次数
//函数
//P460


//getNext求解长度为len的字符串s的next数组
void getNext(char s[], int len)
{
    int j = -1;
    next[0] = -1;
    for(int i = 1; i < len; i++)
    {
        while(j != -1 && s[i] != s[j+1])
        {
            j = next[j];
        }
        if(s[i] == s[j + 1])
        {
            j++;
        }
        next[i] = j;
    }
}

//改进版getNextval求解长度为len的字符串s的nextval数组
void getNextval(char s[], int len)
{
    int j = -1;
    nextval[0] = -1;
    for(int i = 1; i < len; i++)
    {
        while(j != -1 && s[i] != s[j + 1])
        {
            j = nextval[j];
        }
        if(s[i] == s[j + 1])
        {
            j++;
        }
        if(j == -1 || s[i+1] != s[j+1])
        {
            nextval[i] = j;
        }
        else
        {
            nextval[i] = nextval[j];
        }
    }
}

//统计pattern在text中出现的次数
int KMP(char text[], char pattern[])
{
    int n = strlen(text), m = strlen(pattern);
    getNext(pattern, m);
    int ans = 0, j = -1;
    for(int i = 0; i < n; i++)
    {
        while(j != -1 && text[i] != pattern[j + 1])
        {
            j = next[j];
        }
        if(text[i] == pattern[j + 1])
        {
            j++;
        }
        if(j == m - 1)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}

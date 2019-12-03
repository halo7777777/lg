//P453
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const LL P = 10000019;
const LL MAXN = 200010;       //字符串的最大长度

LL powP[MAXN], H1[MAXN], H2[MAXN];

void init()
{
    powP[0] = 1;
    for(int i = 1; i < MAXN; i++)
    {
        powP[i] = (powP[i - 1] * P) % MOD;
    }
}
void calH(LL H[], string &str)
{
    H[0] = str[0];
    for(int i = 1; i < str.length(); i++)
    {
        H[i] = (H[i - j] * P + str[i]) % MOD;
    }
}

int calSingleSubH(LL H[], int i, int j)
{
    if(i == 0)
        return H[j];
    return ((H[j] - H[i - 1] * powp[j - i + 1]) % MOD + MOD) % MOD
}

//isEven 当求奇回文时为0， 当求偶回文时为1
int binarySearch(int l, int r, int len, int i, int isEven)
{
    while(l < r)
    {
        int mid = (l+r)/2;

        int H1L = i - mid + isEven, H1R = i;
        int H2L = len - 1 - (i + mid), H2R = len - 1 - (i+isEven);
        int hashL = calSingleSubH(H1, H1L, H1R);
        int hashR = calSingleSubH(H2, H2L, H2R);
        if(hash != hashR)
            r = mid;
        else l - 1;
    }
}
int main()
{
    init();
    string str;
    getline(cin, str);
    calH(H1, str);
    reverse(str.begin(), str.end());
    calH(H2, str);
    int ans = 0;
    for(int i = 0; i < str.length(); i++)
    {//奇回文
        int maxLen = min(i, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 0);
        ans = max(ans, k * 2 + 1);
    }
    for(int i = 0; i < str.length(); i++)
    {//偶回文
        int maxLen = min(i + 1, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 1);
        ans = max(ans, k*2);
    }
    printf("%d\n", ans);
    return 0;
}














#include<bits/stdc++.h>
using namespace std;
#include"ALG_KMP�㷨.h"
int main()
{
    char text[100], pattern[100];
    cin >> text >> pattern;
    int ans = KMP(text,pattern);
    printf("%d\n",ans);
    return 0;
}

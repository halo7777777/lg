#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a_used[26] = {0};
    int b_used[26] = {0};
    map<char, char> mp;
    string a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < a.length(); i++)
    {
        if((a_used[a[i]-'A'] == 1 && mp[a[i]] != b[i]) || (a_used[a[i]-'A'] == 0 && b_used[b[i]-'A'] == 1))
        {
            printf("Failed");
            return 0;
        }
        mp.insert(pair<char, char>(a[i],b[i]));
        a_used[a[i]-'A'] = 1;
        b_used[b[i]-'A'] = 1;
    }
    for(int i = 0; i < 26; i++)
    {
        if(a_used[i] == 0)
        {
            printf("Failed");
            return 0;
        }
    }
    for(int i =  0; i < c.length(); i++)
    {
            printf("%c",mp[c[i]]);
    }
    return 0;
}

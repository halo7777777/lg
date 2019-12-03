#include<bits/stdc++.h>
using namespace std;
struct bign{
    int d[2001];
    int len;
    bign()
    {
        memset(d,0,sizeof(d));
        len = 0;
    }
};
map<char, int> mp;
int B;
bign change(string a)
{
    bign c;
    c.len = a.length();
    for(int i = 0; i < a.length(); i++)
    {
        c.d[i] = mp[a[a.length()-i-1]];
    }
    return c;
}
bign add(bign a, bign b)
{
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len|| i < b.len; i++)
    {
        int temp = a.d[i] + b.d[i] + carry;
        carry = temp/B;
        temp %= B;
        c.d[c.len++] = temp;
    }
    while(carry)
    {
        c.d[c.len++] = carry%B;
        carry /= B;
    }
    return c;
}
int main()
{
    mp['1'] = 1; mp['2'] = 2; mp['3'] = 3; mp['4'] = 4; mp['5'] = 5;
    mp['6'] = 6; mp['7'] = 7; mp['8'] = 8; mp['9'] = 9; mp['A'] = 10;
    mp['B'] = 11; mp['C'] = 12; mp['D'] = 13; mp['E'] = 14; mp['F'] = 15;
    mp['G'] = 16; mp['H'] = 17; mp['I'] = 18; mp['J'] = 19; mp['K'] = 20;
    mp['L'] = 21; mp['M'] = 22; mp['N'] = 23; mp['O'] = 24; mp['P'] = 25;
    mp['Q'] = 26; mp['R'] = 27; mp['S'] = 28; mp['T'] = 29; mp['U'] = 30;
    mp['V'] = 31; mp['W'] = 32; mp['X'] = 33; mp['Y'] = 34; mp['Z'] = 35;
    string a, b;
    scanf("%d",&B);
    cin >> a >> b;

    bign c = change(a);
    bign d = change(b);

    c = add(c,d);
    for(int i = 0; i < c.len ; i++)
    {
        int temp  = c.len-i-1;
        if(c.d[temp] >= 10)
            printf("%c",c.d[temp]+'A'-10);
        else
            printf("%d",c.d[temp]);
    }
    return 0;
}

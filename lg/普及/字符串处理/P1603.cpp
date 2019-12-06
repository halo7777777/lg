#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp["one"] = 1; mp["two"] = 2; mp["three"] = 3; mp["four"] = 4;
    mp["five"] = 5; mp["six"] = 6; mp["seven"] = 7; mp["eight"] = 8;
    mp["nine"] = 9; mp["ten"] = 10; mp["eleven"] = 11; mp["twelve"] = 12;
    mp["thirteen"] = 13; mp["fourteen"] = 14; mp["fifteen"] = 15; mp["sixteen"] = 16;
    mp["seventeen"] = 17; mp["eighteen"] = 18; mp["nineteen"] = 19; mp["twenty"] = 20;
    mp["a"] = 1; mp["both"] = 3; mp["another"] = 3;
    mp["first"] = 1; mp["second"] = 2; mp["third"] = 3;
    long long sum = 0;
    int num[5] = {0};
    string word;
    for(int i = 0; i < 6; i++)
    {
        cin >> word;
        num[i] = mp[word];
        num[i] = num[i]*num[i]%100;
    }
    sort(num,num+6);
    for(int i = 0; i < 6; i++)
    {
        sum = 100*sum + num[i];
    }
    printf("%lld\n",sum);
    return 0;
}


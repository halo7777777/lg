#include<bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
    return a+b > b+a;       //避免32132大于32321的情况
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<string> vc;
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        vc.push_back(str);
    }
    sort(vc.begin(),vc.end(),cmp);
    for(int i = 0; i < n; i++)
    {
        cout << vc[i];
    }
    return 0;
}

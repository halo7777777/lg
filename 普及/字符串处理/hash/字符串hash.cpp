//给出N个只有小写字母的字符串，求其中不同的字符串的个数
//P449
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD = 1000000007;     //即1e9+7
const int P = 10000019;        //即1e7+19
vector<int> ans;

long long hashFunc(string str)
{
    long long H = 0;
    for(int i = 0; i < str.length(); i++)
    {
        H = (H * P + str[i] - 'a') % MOD;
    }
    return H;
}
int main()
{
    string str;
    while(getline(cin, str), str != "#")     //getline输入一整行数据
    {
        long long id = hashFunc(str);
        ans.push_back(id);
    }
    sort(ans.begin(), ans.end());         //排序
    int cnt = 0;
    for(int i = 0; i < ans.size(); i++)
    {
        if(i == 0 || ans[i] != ans[i-1])    //排序后再查重
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

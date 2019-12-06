//都选，顺序不同
//本题不需要特别判断终止条件，因为所选单词数不一定，用标记数组遍历所有可能
#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> vc;
string temp;
int max_l = 0;
int used[30] = {0};         //标记单词已经使用过
int bf(string a, string b, int i)          //i 表示是取子串的起点，若是开头则为0
{
    int l_min = 1000001;
    for(; i < a.size(); i++)
    {
        int l = a.size()-i;
        if(a.substr(i,l) == b.substr(0,l) && l < b.size())
        {
            if(l < l_min)
            {
                l_min = l;
            }
        }
    }
    return l_min;
}
void DFS(int flag)
{
    for(int i = 0; i < n; i++)
    {
        int l = bf(temp,vc[i],flag);
        if(used[i] < 2 && l != 1000001)
        {
            used[i]++;
            string t_temp = temp;             //注意回溯的字符串要设局部变量

            temp = temp.substr(0,temp.size()-l) + vc[i];
            if(temp.size() > max_l)
            {
                max_l = temp.size();
            }


            DFS(1);

            temp = t_temp;    //注意回溯条件
            used[i]--;        //注意回溯条件
        }
    }
}
int main()
{
    string s;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        vc.push_back(s);
    }

    cin >> temp;
    DFS(0);
    printf("%d",max_l);
    return 0;
}

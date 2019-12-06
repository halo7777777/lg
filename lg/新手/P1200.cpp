#include<bits/stdc++.h>
#define MAXN 10
using namespace std;
int main()
{
    char group[MAXN];
    char comet[MAXN];
    scanf("%s %s",comet,group);
    long long int comet_sum = 1;
    long long int group_sum = 1;
    for(int i = 0; comet[i] != 0; i++)
    {
        comet_sum *= comet[i] - 'A' + 1;
    }
    for(int i = 0; group[i] != 0; i++)
    {
        group_sum *= group[i] - 'A' + 1;
    }
    if(group_sum%47 == comet_sum%47)
        printf("GO");
    else
        printf("STAY");
    return 0;
}

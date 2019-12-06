#include<bits/stdc++.h>
using namespace std;
int main()
{
    double s = 0, x = 0;
    scanf("%lf %lf",&s,&x);
    double length = 0;
    double initial = 7;
    int flag = 0;
    for(int i = 1; ; i++)
    {
        length += initial;
        initial = 0.98*initial;
        if(s - x <= 0)
            flag = 1;
        if(length <= s+x && flag == 1)
        {
            printf("y");
            return 0;
        }
        if(length >= s-x && length <= s+x)
            flag = 1;

        if(length > s+x)
        {
            printf("n");
            return 0;
        }
    }
}


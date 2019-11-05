#include<bits/stdc++.h>
using namespace std;
void func(int n)
{
    if(n == 1);

    else if(n == 0)
        printf("0");
    else if(n == 2)
            printf("2");
    else
    {
        for(int i = 15; ;i--)
        {
            if(pow(2,i) <= n)
            {
                n -= pow(2,i);

                printf("2");
                if(i != 1)
                    printf("(");
                func(i);
                if(i != 1)
                    printf(")");
                if(!n)
                {
                    break;
                }
                printf("+");
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    func(n);
    return 0;
}

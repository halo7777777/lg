#include<bits/stdc++.h>
using namespace std;
int sum = 0;        //记录共进行几次移动
void Move(int n, int start, int goal, int temp)
{
    if(n >= 1)
    {
        //将除了最后一个之外的各个金片移动到temp针
        Move(n-1, start,temp, goal);
        //将最后一块移动到goal针
        printf("Move disk %d from %d to %d. \n", n, start, goal);
        sum++;
        //将temp针上的金片移动到goal针
        Move(n-1, temp, goal, start);
    }
    // else 当 n == 0 时不需要做任何事
}
int main()
{
    int n;
    scanf("%d",&n);
    Move(n,1,3,2);
    printf("sum = %d\n",sum);
}

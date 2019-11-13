#include<cstdio>
#include<iostream>
using namespace std;
int n, a[500010], temp[500010]; //temp数组临时存合并后的数组
long long ans = 0;

void msort(int left, int right)//从小到大的归并排序
{
    if(left < right)
    {   //分
        int mid = (right+left)/2;
        msort(left, mid);
        msort(mid+1,right);
        //合，排序
        int i = left, j = mid+1, k = left; //k为temp数组下标
        while(i <= mid && j <= right)
            if(a[i] <= a[j])
                temp[k++] = a[i++];
            else
            {
                temp[k++] = a[j++];
                ans += mid-i+1;            //统计答案,将a[j]并入数组前，加上所有大于他的数
            }
        while(i <= mid)
            temp[k++] = a[i++];
        while(j <= right)
            temp[k++] = a[j++];
        for(int l = left; l <= right; l++)
            a[l] = temp[l];           //将合并后的序列赋值回数组a
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    msort(0,n-1);
    printf("%lld",ans);
    return 0;
}

# include <stdio.h>
# include <stdlib.h>
using namespace std;

int getMaxSum(int n, int a[]);

int main()
{
    int* a;
    int i,n;
    scanf("%d", &n);
    // 为数组动态分配一个空间     
    a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d", getMaxSum(n, a));
    return 0;
}

int getMaxSum(int n, int a[]) {
    int maxsum = 0, thissum = 0;
    int index;
    //算法思想：在线处理
    for (index = 0; index < n; index++)
    {
        thissum += a[index];
        if (thissum > maxsum)
            maxsum = thissum;
        else if (thissum < 0)
            thissum = 0;
    }
    return maxsum;
}

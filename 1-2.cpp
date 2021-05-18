# include <stdio.h>
# include <stdlib.h>

// 在1-1的基础上增加记录初始值和尾值
int main()
{
    int *a;
    int n,i,first,last,index,count=0;
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int maxsum=0,thissum=0;
    //在线处理，同时每次记录最大子列和maxsum对应的元素信息
     for(i=0;i<n;i++)
    {
           if(a[i]<0)
               count++;//记录负数个数
         thissum+=a[i];
        if(thissum>maxsum)
        {
            maxsum=thissum;
            last=a[i];
            index=i;//更新last的特征
        }
        else if(thissum<0)
            thissum=0;
    }
    thissum=0;
    if(maxsum>0)
         //根据maxsum的值以及记录的last特征进行前扫匹配，需找到first
        //此时数列情况为一定含有正数，需找到first
    for(i=index;i>=0;i--)
    {
          thissum+=a[i];
        if(thissum==maxsum)
        {
            first=a[i];//一定要不断更新first，因为加零maxsum值不会改变，需要找到第一个使之成立的first
        }
         
    }
    else
    {
        if(count==n)//值全为负数
        {
            first=a[0];
            last=a[n-1];
        }
         else
         {
             first=0;
             last=0;
             //数列中不全是负数还有零
         }
    }
     printf("%d %d %d\n",maxsum,first,last);
    return 0;
}



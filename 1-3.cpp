Position BinarySearch( List L, ElementType X )
{
    Position mid,left=1,right=L->Last;
    while(left<=right)
    {
        mid=(right+left)/2;
     //   printf("L->Data[mid]=%d mid= %d\n",L->Data[mid],mid);
        if(L->Data[mid]==X)
            return mid;
        else
            if(L->Data[mid]>X)
            {
                right=mid-1;
            }
        else
            left=mid+1;
    }
    return  NotFound;
}

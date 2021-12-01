#include<stdio.h>
int main()
{
    int x[100],y,n;
    printf("No. of elements in the array: ");
    scanf("%d",&n);
    printf("Input the array elements in increasing order: ");
    for(int i=0;i<n;++i)
    {
        scanf("%d",x+i);
    }
    printf("Element which is to be searched: ");
    scanf("%d",&y);
 
    int low=0,high=n-1;
    int mid,result=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x[mid]==y)
        {
            result=mid;
            break;
        }
        if(x[mid]<y)
        {
            low=mid+1;
        }
        if(x[mid]>y)
        {
            high=mid-1;
        }
        if(low>high)
            break;
    }
    printf("Index of the searched element is %d\n\n",result);
 
    return 0;
}
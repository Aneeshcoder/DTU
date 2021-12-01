#include<stdio.h>
int main()
{
    int arr[100],n;
    printf("No. of elements in the array: ");
    scanf("%d",&n);
    printf("Input the array elements: ");
    for(int i=0;i<n;++i)
    {
        scanf("%d",arr+i);
    }
 
    int min,temp,index;
    for(int i=0;i<n;++i)
    {
        min=arr[i];
        index=i;
        for(int j=i+1;j<n;++j)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                index=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
    
    printf("Sorted array is");
    for(int i=0;i<n;++i)
    {
        printf(" %d",arr[i]);
    }
    printf("\n\n");
    return 0;
}
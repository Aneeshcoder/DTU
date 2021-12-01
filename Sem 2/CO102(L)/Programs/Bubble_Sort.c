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

    int temp;
    for(int j=0;j<n-1;++j)
    {
        for(int i=0;i<n-j-1;++i)
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    
    printf("Sorted array is");
    for(int i=0;i<n;++i)
    {
        printf(" %d",arr[i]);
    }
    printf("\n\n");
    return 0;
}
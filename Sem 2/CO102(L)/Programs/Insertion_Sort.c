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
 
    int temp,k;
    for(int i=1;i<n;++i) 
    {
        temp=arr[i];
        k=i;
        while(k>0 && arr[k-1]>temp) 
        {
            arr[k]=arr[k-1];
            k--;
        }
        arr[k]=temp;
    }
 
    printf("Sorted array is");
    for(int i=0;i<n;++i)
    {
        printf(" %d",arr[i]);
    }
    printf("\n\n");
    return 0;
}
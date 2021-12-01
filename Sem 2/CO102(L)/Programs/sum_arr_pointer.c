#include<stdio.h>
int sum(int *p,int n)
{
    int sum=0;
    for(int i=0;i<n;++i){
        sum=sum+(*(p+i));}
    return sum;
}

int main()
{
    int arr[100],n;
    printf("Number of elements in array: ");
    scanf("%d",&n);
    printf("Enter elements of the array: ");
    for(int i=0;i<n;++i){
        scanf("%d",arr+i);}
    
    int s=sum(arr,n);
    printf("\n%d is the sum of given array\n\n",s);
    return 0;
}
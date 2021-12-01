#include<stdio.h>
float avg(int *p,int n)
{
    int sum=0; 
    for(int i=0;i<n;++i){
        sum=sum+(*(p+i));}
    float average=(float)sum/n;
    return average;
}
 
int main()
{
    int arr[100],n;
    printf("Number of elements in array: ");
    scanf("%d",&n);
    printf("Enter elements of the array: ");
    for(int i=0;i<n;++i){
        scanf("%d",arr+i);}
    float average;
    average=avg(arr,n);
    printf("\n%.2f is the average of given array\n\n",average);
    return 0;
}

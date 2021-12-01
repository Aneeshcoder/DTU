#include<stdio.h>
int main()
{
    int arr[100],n;
    printf("Number of elements in array: ");
    scanf("%d",&n);
    printf("Enter elements of the array: ");
    for(int i=0;i<n;++i){
        scanf("%d",arr+i);}

    int *ptr[100];
    for(int i=0;i<n;++i){
        ptr[i]=arr+i;}

    printf("\nGiven array is");
    for(int i=0;i<n;++i){
        printf(" %d",*ptr[i]);}
    printf("\n\n");
    return 0;
}

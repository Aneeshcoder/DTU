#include<stdio.h>
int main()
{
    int x,n,t,count=1;
    int arr[32];
    printf("Enter the decimal number: ");
    scanf("%d",&x);
    n=x;
    t=n%2;
    if(t==1){arr[32]=1;}
    else{arr[32]=0;}
    n=(n-t)/2;
    
    for(int i=31;n!=0;--i)
    {
        t=n%2;
        n=(n-t)/2;
        arr[i]=t;
        ++count;
    }
    
    printf("Binary number equivalent to %d is ",x);
    for(int i=33-count;i<=32;++i)
    {
        printf("%d",arr[i]);
    }
    printf("\n\n");
    return 0;
}
#include<stdio.h>
int main()
{
    int x;
    printf("Enter the number: ");
    scanf("%d",&x);
    int n=x,rev=0;
    while(n!=0)
    {
        rev=(rev*10)+(n%10);
        n=n/10;
    }
    printf("Reversed number of %d is %d\n\n",x,rev);
    return 0;
}
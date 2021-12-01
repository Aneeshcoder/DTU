#include<stdio.h>
int main()
{
    int x;
    printf("Enter the number: ");
    scanf("%d",&x);
    int n=x,sum=0;
    while(n!=0)
    {
        sum=sum+n%10;
        n=n/10;
    }
    printf("Sum of the digits is %d\n\n",sum);
    return 0;
}
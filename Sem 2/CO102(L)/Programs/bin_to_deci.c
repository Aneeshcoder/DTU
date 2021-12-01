#include<stdio.h>
int main()
{
    int x,pow=1;
    printf("Enter the binary number: ");
    scanf("%d",&x);
    int n=x,num=n%10;
    n=n/10;
    while(n!=0)
    {
        pow=pow*2;
        num=num+(n%10)*pow;
        n=n/10;
    }
    printf("Decimal value for %d binary is %d\n\n",x,num);
    return 0;
}
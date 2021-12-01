#include<stdio.h>
int main()
{
    //Decimal to Binary Conversion

    int x,t,num,binary=0,a=1;
    printf("Enter the decimal number: ");
    scanf("%d",&x);
    printf("\n");
    num=x;
    
    while(num!=0)
    {
        t=num%2;
        num=(num-t)/2;
        if(t==1)
        {
            binary=binary+a;
            a=10*binary;
        }
        else if(t==0)
        {
            a=10*a;
        }
    }
    printf("Binary form of %d decimal is %d\n\n",x,binary);

    //Binary to Decimal conversion

    int pow=1,n=binary,deci=n%10;
    n=n/10;
    while(n!=0)
    {
        pow=pow*2;
        deci=deci+(n%10)*pow;
        n=n/10;
    }
    printf("Decimal value for %d binary is %d\n\n",binary,deci);

    return 0;
}
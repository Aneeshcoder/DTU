#include<stdio.h>
int fact(int x)
{
    if(x==0 || x==1)
        return 1;
    else
        return x*fact(x-1);        
}

int main()
{
    int x;
    printf("Input no. for factorial: ");
    scanf("%d",&x);
    int factorial=fact(x);
    printf("Factorial of no. %d is %d\n\n",x,factorial);
    return 0;
}
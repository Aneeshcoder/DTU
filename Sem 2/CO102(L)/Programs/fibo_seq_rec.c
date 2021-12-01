#include<stdio.h>
int fibo(int n, int x, int y)
{
    if(n==0)
        return 0;
    else
        printf(" %d",y);
    return fibo(n-1,y,x+y);
}

int main()
{
    int n,x,y;
    printf("Enter number of terms to be printed: ");
    scanf("%d",&n);
    x=0,y=1;
    if(n>=1)
        printf("%d",x);
    fibo(n-1,0,1);
    printf("\n\n");
    return 0;
}
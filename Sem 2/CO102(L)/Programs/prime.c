#include<stdio.h>
#include<math.h>
int main()
{
    int n,count=0;
    printf("Input a number: ");
    scanf("%d",&n);
    if(n<=1)
    {
        printf("Neither prime nor composite\n\n");
        count=1;
    }

    for(int i=2;i<=sqrt(n) && count==0;++i)
    {
        if(n%i==0)
        {
            printf("%d is non prime or composite\n\n",n);
            count=1;
        }
    }
    
    if(count==0)
    {
        printf("%d is prime\n\n",n);
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int n,pow;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("Enter the exponential power: ");
    scanf("%d",&pow);
    float x,num=1;
    for(int i=1;i<n;++i)
    {
        x=1;
        for(int r=1;r<=i;++r)
        {
            x=x*(float)pow/r;
        }
        num=num+x;
    }
    printf("e raise to power %d is %f\n\n",pow,num);
    return 0;
}
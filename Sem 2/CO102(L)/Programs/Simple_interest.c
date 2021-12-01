// 2K20/A6/56
// Aneesh Panchal

#include<stdio.h>
int main()
{
    float p,t,r;
    printf("Enter the value of principle amount: ");
    scanf("%f",&p);
    printf("Enter the value of rate of interest: ");
    scanf("%f",&r);
    printf("Enter the number of years: ");
    scanf("%f",&t);

    float simple_interest = p*t*r/100.0;
    printf("Value of simple interest is %.2f\n\n\n",simple_interest);
    return 0;
}
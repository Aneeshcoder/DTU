#include<stdio.h>
int main()
{
    int x,y,sum;
    printf("Enter value of x: ");
    scanf("%d",&x);
    printf("Enter value of y: ");
    scanf("%d",&y);
    sum=x+y;
    float average= (float)sum/2;
    printf("Sum is %d \nAverage is %.2f",sum,average);
    printf("\n\n\n");
    return 0;
}
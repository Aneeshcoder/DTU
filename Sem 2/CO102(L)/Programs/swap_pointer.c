#include<stdio.h>
int main()
{
    int x,y,temp;
    printf("Enter 2 numbers for swapping: ");
    scanf("%d %d",&x,&y);

    int *a=&x;
    int *b=&y;

    temp=*a;
    *a=*b;
    *b=temp;

    printf("\nNumbers after swapping are %d %d\n\n",x,y);
    return 0;
}
#include <stdio.h>
int main() 
{
    int rows,space;
    printf("Odd no. of Rows: ");
    scanf("%d",&rows);
    for(int i=1;i<=rows;i=i+2)
    {
        space=(rows-i)/2;
        for(int r=1;r<=rows;++r)
        {
            if(r<=space || r>(rows-space))
            printf(" ");
            else
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
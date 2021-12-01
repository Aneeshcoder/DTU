#include<stdio.h>
int main()
{
    int x1=0,x2=1,n,x;
    printf("Enter number of terms to be printed: ");
    scanf("%d",&n);
    if(n>=1){printf("%d",x1);}
    if(n>=2){printf(" %d",x2);}
    for(int i=2;i<n;++i)
    {
        x=x2;
        x2=x2+x1;
        x1=x;
        printf(" %d",x2);
    }
    printf("\n\n");
    return 0;
}
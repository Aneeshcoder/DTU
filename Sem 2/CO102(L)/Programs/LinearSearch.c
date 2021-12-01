#include<stdio.h>
int main()
{
    int x[10],y;
    printf("Input the array elements: ");
    for(int i=0;i<10;++i)
    {
        scanf("%d",x+i);
    }
    printf("Element which is to be searched: ");
    scanf("%d",&y);

    int result=-1;
    for(int i=0;i<10;++i)
    {
        if(x[i]==y)
        {
            result=i;
        }
    }
    printf("Index of the searched element is %d\n\n",result);
    return 0;
}
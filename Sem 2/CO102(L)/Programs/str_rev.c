//Aneesh Panchal
//2K20/A6/56

#include<stdio.h>
int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    
    int len=0;
    char temp;
    while(str[len]!='\0')
        ++len;

    for(int i=0;i<len/2;++i)
    {
        temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }

    printf("\nReversed string: ");
    puts(str);
    printf("\n");
    return 0;
}

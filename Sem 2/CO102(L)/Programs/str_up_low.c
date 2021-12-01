//Aneesh Panchal
//2K20/A6/56

#include<stdio.h>
int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    
    int len=0;
    while(str[len]!='\0')
        ++len;

    for(int i=0;i<len;++i)
    {
        if(str[i]>=65 && str[i]<=90)
            str[i]=str[i]+32;
        else if(str[i]>=97 && str[i]<=122)
            str[i]=str[i]-32;
    }
    printf("\nConverted string: ");
    puts(str);
    printf("\n");
    
    return 0;
}

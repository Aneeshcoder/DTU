//Aneesh Panchal
//2K20/A6/56

#include<stdio.h>
int main()
{
    char str[32];
    int count=0;
    printf("Enter a string: ");
    gets(str);

    while(str[count]!='\0')
        count++;
    
    puts(str);
    printf("Length of string: %d\n\n",count);
    return 0;
}

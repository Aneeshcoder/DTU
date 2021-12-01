//Aneesh Panchal
//2K20/A6/56

#include<stdio.h>
int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);

    int count=1;
    int len=0;
    while(str[len]!='\0')
        ++len;

    for(int i=0;i<len;++i)
    {
        if(str[i]!=str[len-i-1])
        {
            count=0;
            break;
        }
    }

    if(count==0)
        printf("Given string is not Palindrome\n\n");
    else
        printf("Given string is Palindrome\n\n");
    return 0;
}

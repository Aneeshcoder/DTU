//Aneesh Panchal
//2K20/A6/56

#include<stdio.h>
int main()
{
    char str1[100],str2[100];
    printf("Enter 1st string: ");
    gets(str1);
    printf("Enter 2nd string: ");
    gets(str2);

    int i=0,j=0;
    while(str1[i]!='\0')
        ++i;
    
    while(str2[j]!='\0')
    {
        str1[i]=str2[j];
        ++i;++j;
    }
    str1[i]='\0';
    
    printf("\nString after concatenation: ");
    puts(str1);
    printf("\n");
    return 0;
}

//Aneesh Panchal
//2K20/A6/56

#include<stdio.h>
int main()
{
    char str[100];
    int count=0,i=0;
    printf("Enter a string: ");
    gets(str);

    while(str[i]!='\0')
    {
        if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' ||
           str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
           {
               ++count;
           }
           ++i;
    }
    puts(str);
    printf("Number of vowels: %d\n\n",count);
    return 0;
}

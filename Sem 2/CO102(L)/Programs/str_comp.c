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
    int count=1,len=0;

    int len1=0,len2=0;
    while(str1[len1]!='\0')
        ++len1;
    while(str1[len2]!='\0')
        ++len2;

    if(len1==len2){len=len1;}
    else if(len1>len2){len=len1;}
    else{len=len2;}

    for(int i=0;i<len;++i)
    {
        if(str1[i]!=str2[i])
        {
            count=0;
            break;
        }
    }
    if(count==0)
        printf("Given string are not same\n\n");
    else
        printf("Given string are same\n\n");
    return 0;
}

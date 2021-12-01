//Aneesh Panchal 2K20/A6/56

#include<stdio.h>
int main()
{
    char low_up;
    printf("Enter the alphabet for lower or upper case: ");
    scanf("%c",&low_up);
    int num=low_up;
    if(num>=97){printf("%c is lower case alphabet",low_up);}
    else{printf("%c is upper case alphabet",low_up);}
    return 0;
}
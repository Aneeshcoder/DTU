#include<stdio.h>
int main()
{
    int x;
    printf("Enter a number for divisibility check: ");
    scanf("%d",&x);
    if(x%5==0 && x%11==0){printf("It is divisible by 5 and 11\n\n");}
    else if(x%5==0){printf("It is divisible by 5 only\n\n");}
    else if(x%11==0){printf("It is divisible by 11 only\n\n");}
    else{printf("It is neither divisible by 5 nor 11\n\n");}
 
    int y;
    printf("Enter a number for odd even check: ");
    scanf("%d",&y);
    if(y%2==0){printf("Number entered is even\n\n");}
    else{printf("Number entered is odd\n\n");}
 
    int year;
    printf("Write the year: ");
    scanf("%d",&year);
    if((year%4==0 && year%100!=0) || year%400==0){printf("Year %d is a leap year\n\n",year);}
    else{printf("Year %d is not a leap year\n\n",year);}
 
    char vow_con = 'a';
    printf("Enter the alphabet: ");
    scanf("%c",&vow_con);
    if(vow_con=='a' || vow_con=='e' || vow_con=='i' || vow_con=='o' || vow_con=='u' ||
        vow_con=='A' || vow_con=='E' || vow_con=='I' || vow_con=='O' || vow_con=='U')
    {printf("%c is vowel\n\n",vow_con);}
    else{printf("%c is consonant\n\n",vow_con);}
 
    char low_up;
    printf("Enter the alphabet for lower or upper case: ");
    scanf("%c",&low_up);
    int num=low_up;
    if(num>=97){printf("%c is lower case alphabet",low_up);}
    else{printf("%c is upper case alphabet",low_up);}
 
    return 0;
}
#include<stdio.h>
int main()
{
    int num;
    printf("Enter the marks out of 100: ");
    scanf("%d",&num);
    printf("\n");
    switch(num/10)
    {
    case 10:
        printf("Grade is E\n\n");
        break;
    case 9:
        printf("Grade is O\n\n");
        break;
    case 8:
        printf("Grade is A+\n\n");
        break;
    case 7:
        printf("Grade is A\n\n");
        break;
    case 6:
        printf("Grade is B\n\n");
        break;
    case 5:
        printf("Grade is C\n\n");
        break;
    case 4:
        printf("Grade is D\n\n");
        break;
    default:
        printf("Grade is F\n\n");
        break;
    }
    return 0;
}
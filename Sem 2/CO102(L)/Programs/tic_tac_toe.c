#include<stdio.h>
struct Student
{
    char *name ;
    int age ;
};
int main()
{
    struct Student s[2][2] = {{{"A",1},{"B",2}},{{"C",3},{"D",4}}}; 
    char *x="cde";
    printf("%s\n",x) ;
    return 0 ;
}
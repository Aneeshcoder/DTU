#include<stdio.h>
int main()
{
    int x; float f; char c;
    //sizeof operator returns the no. of bytes a particular datatype is taking

    printf("int is taking %ld bytes\n",sizeof(x));
    printf("float is taking %ld bytes\n",sizeof(f));
    printf("char is taking %ld bytes\n",sizeof(c));
    return 0;
}
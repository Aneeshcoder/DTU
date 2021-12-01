#include<stdio.h>

void circle()
{
    float r;
    printf("Input radius of the circle: ");
    scanf("%f",&r);
    printf("Area of circle is %.2f\nCircumference of circle is %.2f\n\n",3.14*r*r,2*3.14*r);
}

void rect()
{
    float l,b;
    printf("Input length and breadth of the rectangle: ");
    scanf("%f %f",&l,&b);
    printf("Area of rectangle is %.2f\nPerimeter of circle is %.2f\n\n",l*b,2*(l+b));
}

void sq()
{
    float a;
    printf("Input length of side of square: ");
    scanf("%f",&a);
    printf("Area of square is %.2f\nPerimeter of square is %.2f\n\n",a*a,4*a);
}

void triangle()
{
    float b,h,l1,l2;
    printf("Input length of base and height of triangle: ");
    scanf("%f %f",&b,&h);
    printf("Input length of other 2 sides of triangle: ");
    scanf("%f %f",&l1,&l2);
    printf("Area of triangle is %.2f\nPerimeter of triangle is %.2f\n\n",0.5*b*h,b+l1+l2);    
}

int main()
{
    int n;
    printf("Write the no. of figure you want:\n");
    printf("1. Cirlce\n2. Rectangle\n3. Square\n4. Triangle\n");
    printf("Write the input: ");
    scanf("%d",&n);
    printf("\n");
    switch(n)
    {
        case 1:
            circle();
            break;
        case 2:            
            rect();
            break;
        case 3:
            sq();
            break;
        case 4:
            triangle();
            break;
        default:
            printf("Invalid Input");
            break;
    }
    return 0;
}

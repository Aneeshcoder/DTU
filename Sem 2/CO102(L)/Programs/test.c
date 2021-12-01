//Aneesh Panchal
//2K20/A6/56
/*
#include<stdio.h>
#include<string.h>
typedef struct
{
    char title[100];
    char author[100];
    int price;
    int flag;
}
book;

int main()
{
    book book_list[5]={{"V1","AB",100,1},{"W1","BC",200,0},
                        {"X1","CD",300,1},{"Y1","DE",400,0},{"Z1","EF",500,1}};

    char arr[100];
    printf("Enter the title of the book: ");
    gets(arr);

    for(int i=0;i<5;++i)
    {
        if(!strcmp(arr,book_list[i].title))
        {
            if(book_list[i].flag)
            {
                printf("Book is available.\n");
            }
            else
            {
                printf("Book is not available.\n");
            }
            printf("Author of the book is %s\n",book_list[i].author);
            printf("Price of the book is %d\n\n",book_list[i].price);
            break;
        }
        else
            continue;
    }
    return 0;
}
*/

#include<stdio.h>

struct student{
char name;
int age;
};

int main()
{
    student s={'x',10};
    *ptr=&s;
    printf("%c",ptr->name);
    return 0;
}
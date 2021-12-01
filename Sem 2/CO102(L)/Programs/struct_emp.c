//Aneesh Panchal
//2K20/A6/56

#include<stdio.h>
typedef struct
{
    char name[100];
    int age;
    int salary;
}
employee;

int main()
{
    employee emp[100];
    int n;
    printf("Enter number of employees: ");
    scanf("%d",&n);

    for(int i=0;i<n;++i)
    {
        printf("\nDetails of employee %d:\n",i+1);
        printf("Name: ");
        scanf("%s",emp[i].name);

        printf("Age: ");
        scanf("%d",&emp[i].age);

        printf("Salary: ");
        scanf("%d",&emp[i].salary);
    }

    printf("\n\nDetails of employees:\n");
    for(int i=0;i<n;++i)
    {
        printf("Employee number %d:\n",i+1);
        printf("Name: %s\n",emp[i].name);
        printf("Age: %d\n",emp[i].age);
        printf("Salary: %d\n\n",emp[i].salary);
    }
    return 0;
}

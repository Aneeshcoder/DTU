#include<stdio.h>
int main()
{
    int x[3][3],y[3][3],z[3][3];
    printf("Enter the elements of 1st 3X3 matrix:\n");
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            scanf("%d",&x[i][j]);
        }
    }
    printf("\nEnter the elements of 2nd 3X3 matrix:\n");
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            scanf("%d",&y[i][j]);
        }
    }
    printf("\nMatrix after addition is\n");
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            z[i][j]=0;
            z[i][j]=x[i][j]+y[i][j];
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            printf("%d ",z[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
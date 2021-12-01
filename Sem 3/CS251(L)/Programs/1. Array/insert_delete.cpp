//Aneesh Panchal
//2K20/MC/21

#include<bits/stdc++.h>
using namespace std;

void insertion(int *arr,int x,int n);
int deletion(int *arr,int x,int n);

int main()
{
    int flag;
    int arr[101]={1,3,5,7,9};
    int x;

    int n=5;    
    int num=0,y=0;
    cout<<"Enter number of elements you want to add: ";
    cin>>num;
    if(num>95)
    {
        cout<<"Error"<<endl<<endl;
        return 0;
    }

    for(int i=0;i<num;++i)
    {
        y=0;
        cout<<"Enter element you want to insert: ";
        cin>>y;
        fflush(stdin);
        insertion(arr,y,n);
        n++;
    }

    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    num=0;
    cout<<"Enter number of elements you want to delete: ";
    cin>>num;
    if(num>n)
    {
        cout<<"Error"<<endl<<endl;
        return 0;
    }
    
    for(int i=0;i<num;++i)
    {
        y=0;
        cout<<"Enter element you want to delete: ";
        cin>>y;
        fflush(stdin);
        flag=deletion(arr,y,n);
        if(flag==(-1))
            cout<<"Element not present !!!"<<endl<<endl;
        else
            --n;
    }
    
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    return 0;
}

void insertion(int *arr,int x,int n)
{
    int index=(-1);
    for(int i=0;i<n;++i)
    {
        if((*(arr+i))>x)
        {
            index=i;
            break;
        }
        else
            continue;        
    }
    if(index==(-1))
        index=(++n);
    for(int i=n;i>=index;i--)
    {
        *(arr+i+1)=*(arr+i);
    }
    *(arr+index)=x;
}

int deletion(int *arr,int x,int n)
{
    int index=(-1);
    for(int i=0;i<n;++i)
    {
        if(*(arr+i)==x)
        {
            index=i;
            break;
        }
        else
            continue;        
    }
    if(index==(-1))
        return -1;
    n--;
    for(int i=index;i<=n;i++)
    {
        *(arr+i)=*(arr+i+1);
    }
    return 1;
}

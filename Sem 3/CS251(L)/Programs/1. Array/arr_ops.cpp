//Aneesh Panchal
//2K20/MC/21

#include<iostream>
using namespace std;

int linear_search(int arr[],int n,int x);
int binary_search(int arr[],int n,int x);

int main()
{
    int arr[101]={1,2,3,4,5,6,7,8,9,10};
    int x;
    cout<<"Enter element you want to search: ";
    cin>>x;
    int n=10;
    int L=linear_search(arr,n,x);
    int B=binary_search(arr,n,x);
    if((L!=-1) && (B!=-1))
        cout<<"Index by Linear Search is "<<L<<endl<<"Index by Binary Search is "<<B<<endl<<endl;
    else
        cout<<"Error"<<endl<<endl;
    return 0;
}

int linear_search(int arr[],int n,int x)
{
    int result=-1;
    for(int i=0;i<n;++i)
    {
        if(arr[i]==x)
        {
            result=i;
            break;
        }
    }
    return result;
}

int binary_search(int arr[],int n,int x)
{
    int low=0,high=n;
    int mid;
    while (low<=high)
    {
        int middle=low+(high-low)/2;
        if (arr[middle]==x)
            return middle;
        if (arr[middle]<x)
            low=middle+1;
        else
            high=middle-1;
   }
   return -1;
}

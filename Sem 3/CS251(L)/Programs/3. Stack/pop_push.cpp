//Aneesh Panchal
//2K20/MC/21
 
#include<iostream>
using namespace std;

#define len 5
class stack{
    public:
        int arr[len];
        int top=-1;
    
    void push(int x){
        if(top==len-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            ++top;
            arr[top]=x;
        }
    }
 
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else{
            arr[top]=-1;
            --top;
        }
    }
    int Top_Element(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
 
};
 
int main()
{
    stack stak;
    int number,operation,element;
    cout<<"Enter number of operations you want to perform: ";
    cin>>number;
    for(int i=0;i<number;++i)
    {
        cout<<"Enter\n1: Push element\n2: Pop element\n3: See Top element\nOperation: ";
        cin>>operation;
        if(operation == 1)
        {
            cout<<"Enter the element: ";
            cin>>element;
            stak.push(element);
        }
        else if(operation == 2)
            stak.pop();
        else if(operation == 3)
            cout<<"Top element is "<<stak.Top_Element()<<endl;
        else{
            cout<<"Please Enter a valid operation number"<<endl;
            --i;
        }
        cout<<endl;
    }
    return 0;
}
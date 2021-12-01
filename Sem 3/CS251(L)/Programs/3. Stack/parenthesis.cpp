//Aneesh Panchal
//2K20/MC/21
 
#include<iostream>
#include<string>
using namespace std;
 
#define len 101
class stack{
    public:
        char array[len];
        int top=-1;
    
    void push(char x){
        if(top==len-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            ++top;
            array[top]=x;
        }
    }
 
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else{
            array[top]='X';
            --top;
        }
    }
 
    char Top_Element(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return array[top];
    }
 
    bool empty(){
        return top==-1;
    }
};
 
bool isvalid(string paranthesis){
    int length = paranthesis.length();
    stack stak;
    for (int i=0;i<length;++i){
        if(paranthesis[i]=='{' or paranthesis[i]=='[' or paranthesis[i]=='(')
            stak.push(paranthesis[i]);
        else if(paranthesis[i]==')')
            if(stak.Top_Element()=='(')
                stak.pop();
            else
                return false;
        else if(paranthesis[i]==']')
            if(stak.Top_Element()=='[')
                stak.pop();
            else
                return false;
        else if(paranthesis[i]=='}')
            if(stak.Top_Element()=='{')
                stak.pop();
            else
                return false;
    }
    if(!stak.empty())
        return false;
    return true;
}
 
int main(){
    string paranthesis;
    cout<<"Enter the paranthesis string"<<endl;
    getline(cin,paranthesis);
    cout<<endl;
    if(paranthesis.length()>=50)
    {
        cout<<"Please shorten the length of the string"<<endl;
        return 0;
    }
    else{
        if(isvalid(paranthesis))
            cout<<"Balanced Paranthesis"<<endl<<endl;
        else
            cout<<"Imbalanced Paranthesis"<<endl<<endl;
    }
    return 0;
}
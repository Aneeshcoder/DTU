#include<bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* next=NULL;
};
 
class StackLinkedList {
    Node* head;
    Node* rear;
  
    public:
        StackLinkedList(){head = NULL;}
  
    void push(int data_){
        Node* newNode = new Node();
        newNode->data = data_;
        
        Node* temp=head;
 
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            rear = newNode;
            return;
        }
 
        newNode->next = head;
        head = newNode;
        return;    
    }
  
    void show(){
        Node* temp=head;
 
        if(head==NULL){
            cout<<"List Empty"<<endl<<endl;
            return;
        }
 
        while(temp!=rear){
            cout<< temp->data <<" -> ";
            temp = temp->next;
        }
        cout<<temp->data<<" and "<<rear->data<<endl<<endl;
    }
    
    void top(){
        cout<<head->data<<endl<<endl;
    }
 
    void pop(){
        Node* temp=head;
 
        if(head==NULL){
            cout<<"List empty"<<endl<<endl;
            return;
        }
 
        if(head==rear){
            head=NULL;
            rear=NULL;
        }
        else{
            head = temp->next;
        }
        return;    
    }
 
    bool isempty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};
 
int main()
{
    StackLinkedList stackLL;
    stackLL.push(1);
    stackLL.show();
    stackLL.push(2);
    stackLL.show();
    stackLL.push(3);
    stackLL.show();
    stackLL.push(4);
    stackLL.show();
    stackLL.push(5);
    stackLL.show();
    stackLL.push(6);
    stackLL.show();
    stackLL.push(7);
    stackLL.show();
    stackLL.push(8);
    stackLL.show();
 
    stackLL.top();
    stackLL.pop();
    stackLL.show();
    stackLL.pop();
    stackLL.show();
    stackLL.pop();
    stackLL.show();
    stackLL.pop();
    stackLL.show();
    return 0;
}

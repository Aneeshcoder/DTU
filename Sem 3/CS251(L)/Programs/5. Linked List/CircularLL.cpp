#include<bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* next=NULL;
};
 
class CircularLinkedList {
    Node* head;
    Node* rear;
  
    public:
        CircularLinkedList(){head = NULL;}
  
    void insert(int data_){
        Node* newNode = new Node();
        newNode->data = data_;
        
        Node* temp=head;
 
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            rear = newNode;
            return;
        }
 
        else if(head->data > data_){
            newNode->next = head;
            head = newNode;
            return;    
        }
 
        while(temp->next != head && temp->next->data<data_){
            temp = temp->next;
        }
        if(temp->next == head){
            rear = newNode;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
  
    void print(){
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
 
    void deleted(int data_){
        Node* temp=head;
 
        if(head==NULL){
            cout<<"List empty"<<endl<<endl;
            return;
        }
 
        else if(head->data == data_){
            if(head==rear){
                head=NULL;
                rear=NULL;
            }
            else{
                head = temp->next;
            }
            return;    
        }
 
        while(temp->next->data!=data_){
            if(temp->next->next==head){
                cout<<data_<<" "<<"not present in the list"<<endl<<endl;
                return;
            }
            temp=temp->next;
        }
        if(temp->next==rear){
            rear = temp;
        }
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
};
 
int main(){
    CircularLinkedList circularLL;
    cout<<endl;
    circularLL.deleted(10);
    circularLL.insert(1);
    circularLL.print();
    circularLL.deleted(1);
    circularLL.print();
    circularLL.insert(2);
    circularLL.print();
    circularLL.insert(3);
    circularLL.print();
    circularLL.insert(4);
    circularLL.print();
    circularLL.insert(5);
    circularLL.print();
    circularLL.insert(6);
    circularLL.print();
    circularLL.insert(7);
    circularLL.print();
 
    circularLL.deleted(2);
    circularLL.print();
    circularLL.deleted(7);
    circularLL.print();
    circularLL.deleted(100);
    circularLL.print();
    circularLL.deleted(4);
    circularLL.print();
 
    cout<<endl;
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* next=NULL;
};
 
class QueueLinkedList {
    Node* head;
    Node* rear;
  
    public:
        QueueLinkedList(){head = NULL;}
  
    void enqueue(int data_){
        Node* newNode = new Node();
        newNode->data = data_;
        
        Node* temp=head;
 
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            rear = newNode;
            return;
        }
 
        while(temp->next != head){
            temp = temp->next;
        }
        if(temp->next == head){
            rear = newNode;
        }
        newNode->next = temp->next;
        temp->next = newNode;
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
 
    void dequeue(){
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
};
 
int main()
{
    QueueLinkedList QLL;
    QLL.enqueue(1);
    QLL.show();
    QLL.enqueue(2);
    QLL.show();
    QLL.enqueue(3);
    QLL.show();
    QLL.enqueue(4);
    QLL.show();
    QLL.enqueue(5);
    QLL.show();
    QLL.enqueue(6);
    QLL.show();
    QLL.enqueue(7);
    QLL.show();
    QLL.enqueue(8);
    QLL.show();
 
    QLL.dequeue();
    QLL.show();
    QLL.dequeue();
    QLL.show();
    QLL.dequeue();
    QLL.show();
    QLL.dequeue();
    QLL.show();
    return 0;
}

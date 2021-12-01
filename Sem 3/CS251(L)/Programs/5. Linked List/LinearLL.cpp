#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next=NULL;
};

class Linkedlist {
    Node* head;
  
    public:
        Linkedlist(){head = NULL;}
  
    void insert(int data_){
        Node* newNode = new Node();
        newNode->data = data_;
        
        Node* temp=head;

        if(head == NULL){
            head = newNode;
            return;
        }

        else if(head->data > data_){
            newNode->next = head;
            head = newNode;
            return;    
        }

        while(temp->next != NULL && temp->next->data<data_){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
  
    void print(){
        Node* temp=head;

        while(temp!=NULL){
            cout<< temp->data <<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl<<endl;
    }

    void deleted(int data_){
        Node* temp=head;

        if(head==NULL){
            cout<<"List empty"<<endl<<endl;
            return;
        }
        
        else if(head->data == data_){
            head = temp->next;
            return;    
        }

        while(temp->next->data!=data_){
            if(temp->next->next==NULL){
                cout<<data_<<" "<<"not present in the list"<<endl<<endl;
                return;
            }
            temp=temp->next;
        }
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
};

int main()
{
    Linkedlist linkedL;
    cout<<endl;
    linkedL.deleted(4);
    linkedL.print();

    linkedL.insert(9999);
    linkedL.print();

    linkedL.insert(445);
    linkedL.print();

    linkedL.insert(3214);
    linkedL.print();

    linkedL.insert(4);
    linkedL.print();

    linkedL.deleted(4);
    linkedL.print();

    linkedL.deleted(100);
    linkedL.print();

    linkedL.deleted(3214);
    linkedL.print();

    linkedL.deleted(9999);
    linkedL.print();
    cout<<endl;
    
    return 0;
}
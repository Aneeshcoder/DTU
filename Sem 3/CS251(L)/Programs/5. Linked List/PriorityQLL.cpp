#include<bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    int priority;
    Node* next=NULL;
};
 
class PriorityQueueLinkedList {
    Node* head;
  
    public:
        PriorityQueueLinkedList(){head = NULL;}
  
    void enqueue(int data_,int prior){
        Node* newNode = new Node();
        newNode->data = data_;
        newNode->priority = prior;
        Node* temp=head;

        if(head == NULL){
            head = newNode;
            return;
        }

        else if(head->priority > prior){
            newNode->next = head;
            head = newNode;
            return;    
        }

        while(temp->next != NULL && temp->next->priority <= prior){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
  
    void show(){
        Node* temp=head;

        while(temp!=NULL){
            cout<< temp->data << "(" << temp->priority << ")" <<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl<<endl;
    }

    void dequeue(){
        Node* temp=head;

        if(head==NULL){
            cout<<"List empty"<<endl<<endl;
            return;
        }
        Node* del = head;
        head = temp->next;
        delete del;
    }
};

int main()
{
    PriorityQueueLinkedList PQLL;
    cout<<endl<<"Node representation = Data(Priority)"<<endl<<endl;
    PQLL.enqueue(1,5);
    PQLL.show();
    PQLL.enqueue(2,2);
    PQLL.show();
    PQLL.enqueue(3,1);
    PQLL.show();
    PQLL.enqueue(4,2);
    PQLL.show();
    PQLL.enqueue(5,1);
    PQLL.show();
    PQLL.enqueue(6,3);
    PQLL.show();
    PQLL.enqueue(7,4);
    PQLL.show();
    PQLL.enqueue(8,10);
    PQLL.show();

    PQLL.dequeue();
    PQLL.show();
    PQLL.dequeue();
    PQLL.show();
    PQLL.dequeue();
    PQLL.show();
    PQLL.dequeue();
    PQLL.show();
    return 0;
}

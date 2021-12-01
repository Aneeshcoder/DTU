#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data=-1;
    Node* right=NULL;
    Node* left=NULL;
};

class BinarySearchTree {
    Node* root;

    public:
        BinarySearchTree(){root = NULL;}
  
    void insert(int data_){
        Node* newNode = new Node();
        newNode->data = data_;
        
        Node* temp=root;
        Node* pnode=temp;
        if(root->left==NULL && root->right==NULL && root->data==-1){
            root=newNode;
            return;
        }
        else if((root->left==NULL || root->right==NULL) && root->data!=-1){
            if(root->data>data_){
                root->left = newNode;
            }
            else{
                root->right = newNode;
            }
        }

        while(temp!=NULL){
        if(temp->data>data_){
            temp = temp->left;
        }
        else {
            temp=temp->right;
        }
        newNode = temp;

    }
};
  
    /*void print(){
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
            head = head->next;  
            head->prev = NULL;   
            return;    
        }

        while(temp->next->data!=data_){
            if(temp->next->next==NULL){
                cout<<data_<<" "<<"not present in the list"<<endl<<endl;
                return;
            }
            temp=temp->next;
        }

        if(temp->next->next == NULL)  
        {
            Node* del = temp->next->next;
            temp->next = NULL;
            delete del;
        }
        else
        {
            Node* del = temp->next;
            temp->next = del->next;  
            del->next->prev = temp; 
            delete del;
        }
    }*/
};

int main(){
    BinarySearchTree BST;
    BST.insert(10);
    return 0;
}
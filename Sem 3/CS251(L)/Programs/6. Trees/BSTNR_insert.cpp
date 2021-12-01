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
        Node* temp = root;
        Node* newNode = new Node();
        newNode->data = data_;
        if(root==NULL){
            root = newNode;
            return;
        }
        while(1){
            if(data_<temp->data){
                if(temp->left==NULL){
                    temp->left = newNode;
                    return;
                }
                else
                    temp = temp->left;
            }
            else{
                if(temp->right==NULL){
                    temp->right = newNode;
                    return;
                }
                else
                    temp = temp->right;
            }
        }
    }

    void show(){
        stack<Node*> nodestack;
        Node *curr = root;
        if(root==NULL){
            cout<<"Empty Tree !!!!!"<<endl;
            return;
        }
        while(curr!=NULL || nodestack.empty()==false){
            while(curr!=NULL){
                nodestack.push(curr);
                curr = curr->left;
            }
            curr = nodestack.top();
            nodestack.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        cout<<endl;        
    }
};

int main(){
    BinarySearchTree BST;
    cout<<endl;
    BST.show(); //Error
    BST.insert(5);
    BST.insert(3);
    BST.insert(2);
    BST.insert(6);
    BST.insert(4);
    BST.insert(1);
    BST.insert(10);
    BST.insert(7);
    BST.insert(9);
    BST.insert(8);
    BST.insert(11);
    BST.insert(12);
    cout<<endl<<"After Insertion: "<<endl<<"Inorder Traversal: "<<endl;
    BST.show();
    cout<<endl<<endl;
    return 0;
}
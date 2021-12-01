#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
};

Node* insert(Node* root,int data_){
    if(root==NULL){
        Node* newNode = new Node;
        newNode->data = data_;
        return newNode;
    }
    if(data_<root->data){
        root->left = insert(root->left,data_);
    }
    else{
        root->right = insert(root->right,data_);
    }
}

void show(Node *Root){
    if(Root==NULL){
        return;
    }
    show(Root->left);
    cout<<Root->data<<" ";
    show(Root->right);
}

int main(){
    Node* root = NULL;
    root = insert(root,5);
    root = insert(root,3);
    root = insert(root,2);
    root = insert(root,6);
    root = insert(root,4);
    root = insert(root,1);
    root = insert(root,10);
    root = insert(root,7);
    root = insert(root,9);
    root = insert(root,8);
    root = insert(root,11);
    root = insert(root,12);
    cout<<endl<<"Inorder Traversal: "<<endl;
    show(root);
    cout<<endl<<endl;
    return 0;
}
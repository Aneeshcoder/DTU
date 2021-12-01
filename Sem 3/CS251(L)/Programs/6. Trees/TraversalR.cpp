#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
};

void inorder(Node *Root){
    if(Root==NULL){
        return;
    }
    inorder(Root->left);
    cout<<Root->data<<" ";
    inorder(Root->right);
}

void preorder(Node *Root){
    if(Root==NULL){
        return;
    }
    cout<<Root->data<<" ";
    preorder(Root->left);
    preorder(Root->right);
}

void postorder(Node *Root){
    if(Root==NULL){
        return;
    }
    postorder(Root->left);
    postorder(Root->right);
    cout<<Root->data<<" ";
}

int main(){
    Node *n1 = new Node;
    Node *n2 = new Node;
    Node *n3 = new Node;
    Node *n4 = new Node;
    Node *n5 = new Node;
    Node *n6 = new Node;
    Node *n7 = new Node;
    Node *n8 = new Node;
    
    n1->data = 1;
    n2->data = 2;
    n3->data = 3;
    n4->data = 4;
    n5->data = 5;
    n6->data = 6;
    n7->data = 7;
    n8->data = 8;

    n1->left = n2; n1->right = n3;
    n2->left = n4; n2->right = n6;
    n4->right = n5;
    n3->left = n7; n3->right = n8;

    cout<<endl<<"Inorder Traversal: "<<endl;
    inorder(n1);
    cout<<endl;

    cout<<endl<<"Preorder Traversal: "<<endl;
    preorder(n1);
    cout<<endl;

    cout<<endl<<"Postorder Traversal: "<<endl;
    postorder(n1);
    cout<<endl<<endl;
    return 0 ;   
}

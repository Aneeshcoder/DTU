#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
};

int nodes(Node *root){
    if(root==NULL)
        return 0;
    return 1 + nodes(root->left) + nodes(root->right);
}

int leaf(Node *root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return leaf(root->left) + leaf(root->right);
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

    int num_nodes = nodes(n1);
    int num_leaves = leaf(n1);
    cout<<endl;
    cout<<"Number of Nodes: "<<num_nodes<<endl<<"Number of Leaves: "<<num_leaves<<endl;
    cout<<endl;
    return 0;
}

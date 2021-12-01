#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
};

int check(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
        return 1;
    return (root1 && root2) && (root1->data == root2->data) && check(root1->left,root2->left) && check(root1->right,root2->right);
}

int identical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
        return 0;
    else{
        int equal = check(root1,root2);
        return equal;
    }
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

    Node *m1 = new Node;
    Node *m2 = new Node;
    Node *m3 = new Node;
    Node *m4 = new Node;
    Node *m5 = new Node;
    Node *m6 = new Node;
    Node *m7 = new Node;
    Node *m8 = new Node;
    
    m1->data = 1;
    m2->data = 2;
    m3->data = 3;
    m4->data = 4;
    m5->data = 5;
    m6->data = 6;
    m7->data = 7;
    m8->data = 8;

    m1->left = m2; m1->right = m3;
    m2->left = m4; m2->right = m6;
    m4->right = m5;
    m3->left = m7; m3->right = m8;

    int same1 = identical(n1,m1);
    cout<<endl;
    if(same1)
        cout<<"Trees are same !!!"<<endl;
    else
        cout<<"Trees are not same !!!"<<endl;
    
    m8->data = 9;
    cout<<endl<<"After changing data of m8 Node: "<<endl;
    int same2 = identical(n1,m1);
    if(same2)
        cout<<"Trees are same !!!"<<endl;
    else
        cout<<"Trees are not same !!!"<<endl;
    cout<<endl;
    return 0;
}

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

    int findmax(Node* temp){
        int max=0;
        do{
            if(temp->data>max){
                max=temp->data;
            }
            temp = temp->right;
        }
        while(temp!=NULL);
        return max;
    }

    void deletion(int data_){
        int count=-1;
        int max=-1;
        Node* temp = root;
        Node* parent = root;
        Node* newNode = new Node();
        newNode->data = data_;
        if(root==NULL){
            cout<<"Tree does not exist !!!!!"<<endl;
            return;
        }

        while(1){
            if(data_==temp->data){
                //leaf node
                if(temp->left==NULL && temp->right==NULL){
                    if(temp==root)
                        root=NULL;
                    else if(count==0)
                        parent->left = NULL;
                    else
                        parent->right = NULL;
                    return;
                }
                
                //both nodes
                if(temp->left!=NULL && temp->right!=NULL){
                    max = findmax(temp->left);
                    deletion(max);
                    temp->data = max;
                    return;
                }

                //left node
                else if(temp->left!=NULL){
                    if(root==temp)
                        root = temp->left;
                    else if(count==0)
                        parent->left = temp->left;
                    else
                        parent->right = temp->left;
                    return;
                }

                //right node
                else{
                    if(root==temp)
                        root = temp->right;
                    else if(count==0)
                        parent->left = temp->right;
                    else
                        parent->right = temp->right;
                    return;
                }
            }

            //traversal to find particular node
            if(data_<temp->data){
                if(temp->left==NULL){
                    cout<<"Value Doesn't Exist !!!!!"<<endl;
                    return;
                }
                else{
                    parent = temp;
                    temp = temp->left;
                    count = 0;
                }
            }
            else{
                if(temp->right==NULL){
                    cout<<"Value Doesn't Exist !!!!!"<<endl;
                    return;
                }
                else{
                    parent = temp;
                    temp = temp->right;
                    count = 1;
                }
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
    BST.show(); //Error
    BST.deletion(1); //Error
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

    cout<<endl;
    BST.show();
    cout<<endl;
    
    BST.show();
    BST.deletion(1); //leaf node
    BST.deletion(3); //both node
    BST.deletion(9); //left node
    BST.deletion(7); //right node
    BST.deletion(9); //Error

    cout<<endl;
    BST.show();
    cout<<endl;
    return 0;
}
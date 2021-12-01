#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

class Node {
public:
    int data=-1;
    int height=0;
    Node* right=NULL;
    Node* left=NULL;
};

class AVLTree {
    Node* root;

    public:
        AVLTree(){root=NULL;}
    
    int height(Node* n){
        if(n==NULL)
            return -1;
        else{
            int ldepth=height(n->left);
            int rdepth=height(n->right);
            if(ldepth>rdepth)
                return ldepth+1;
            else
                return rdepth+1;
        }
    }

    Node* LL(Node* n){
        Node* newNode = n->left;
        n->left = newNode->right;
        newNode->right = n;
        return newNode;
    }

    Node* RR(Node* n){
        Node* newNode = n->right;
        n->right = newNode->left;
        newNode->left = n;
        return newNode;
    }

    Node* LR(Node* n){
        n->left = RR(n->left);
        return LL(n);
    }

    Node* RL(Node* n){
        n->right = LL(n->right);
        return RR(n);
    }

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
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right==NULL){
                    temp->right = newNode;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }

        if(height(root->right)-height(root->left)==-2){
            if(data_<root->left->data)
                root = LL(root);
            else
                root = LR(root);
        }
        else if(height(root->right)-height(root->left)==2){
            if(data_<root->right->data)
                root = RL(root);
            else
                root = RR(root);
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
        cout<<"------------------"<<root->data<<endl; 
    }
};

int main()
{
    AVLTree avl;
    avl.insert(63);
    avl.show();
    avl.insert(9);
    avl.show();
    avl.insert(19);
    avl.show();
    avl.insert(27);
    avl.show();
    avl.insert(18);
    avl.show();
    avl.insert(108);
    avl.show();
    avl.insert(99);
    avl.show();
    avl.insert(81);
    avl.show();

    return 0;
}
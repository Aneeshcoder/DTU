//8-Puzzle problem using A* algorithm
//Aneesh Panchal
//2K20/MC/21

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    vector<vector<int>> data;
    Node *n1, *n2, *n3, *n4;
    int depth;
};

Node *createNode(vector<vector<int>> data, int depth){
    Node *node = new Node;
    node->data = data;
    node->n1 = node->n2 = node->n3 = node->n4 = NULL;
    node->depth = depth;
    return node;
}

vector<vector<int>> moveUp(vector<vector<int>> data){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(data[i][j] == 0){
                if(i == 0)
                    return data;
                else{
                    data[i][j] = data[i-1][j];
                    data[i-1][j] = 0;
                    return data;
                }
            }
        }
    }
}

vector<vector<int>> moveDown(vector<vector<int>> data){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(data[i][j] == 0){
                if(i == 2)
                    return data;
                else{
                    data[i][j] = data[i+1][j];
                    data[i+1][j] = 0;
                    return data;
                }
            }
        }
    }
}

vector<vector<int>> moveLeft(vector<vector<int>> data){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(data[i][j] == 0){
                if(j == 0)
                    return data;
                else{
                    data[i][j] = data[i][j-1];
                    data[i][j-1] = 0;
                    return data;
                }
            }
        }
    }
}

vector<vector<int>> moveRight(vector<vector<int>> data){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(data[i][j] == 0){
                if(j == 2)
                    return data;
                else{
                    data[i][j] = data[i][j+1];
                    data[i][j+1] = 0;
                    return data;
                }
            }
        }
    }
}

int h(vector<vector<int>> data, vector<vector<int>> goal = {{1,2,3},{8,0,4},{7,6,5}}){
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(data[i][j] != goal[i][j])
                count++;
        }
    }
    return count;
}

int fval(int gval, int hval){
    return gval + hval;
}

struct cmp{
    inline bool operator() (Node* a, Node* b){
        return a->depth + h(a->data) > b->depth + h(b->data);
    }
};

void printmat(Node *node){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<node->data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"f() = h() + g(): "<<fval(node->depth,h(node->data))<<endl;
    cout<<endl;
}

vector<vector<int>> findSol(vector<vector<int>> start, vector<vector<int>> goal){
    priority_queue<Node*, vector<Node*>, cmp> q;
    Node *root = createNode(start,0);
    q.push(root);
    int i=0;
    int deep = 0;
    int min = 0;
    while(!q.empty()){
        Node *temp = q.top();
        q.pop();
        ++i;
        printmat(temp);
        min = fval(temp->depth, h(temp->data));
        if((temp->data == goal) && (min <= fval(q.top()->depth, h(q.top()->data)))){
            cout<<"Number of nodes expanded: "<<i<<endl;
            cout<<"Solution found after "<<temp->depth<<" moves"<<endl;
            cout<<"Goal State Reached"<<endl;
            return temp->data;
        }
        else{
            deep = temp->depth;
            vector<vector<int>> up = moveUp(temp->data);
            vector<vector<int>> down = moveDown(temp->data);
            vector<vector<int>> left = moveLeft(temp->data);
            vector<vector<int>> right = moveRight(temp->data);
            if(up != temp->data){
                Node *node = createNode(up,deep+1);
                temp->n1 = node;
                q.push(node);
            }
            if(down != temp->data){
                Node *node = createNode(down,deep+1);
                temp->n2 = node;
                q.push(node);
            }
            if(left != temp->data){
                Node *node = createNode(left,deep+1);
                temp->n3 = node;
                q.push(node);
            }
            if(right != temp->data){
                Node *node = createNode(right,deep+1);
                temp->n4 = node;
                q.push(node);
            }
        }
    }
}

int main(){
    vector<vector<int>> start = {{2,8,3},{1,6,4},{7,0,5}};
    vector<vector<int>> goal = {{1,2,3},{8,0,4},{7,6,5}};
    vector<vector<int>> sol = findSol(start, goal);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

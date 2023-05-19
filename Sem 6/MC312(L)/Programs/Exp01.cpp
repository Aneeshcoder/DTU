//8-Puzzle problem using Generate and Test Strategy
//Aneesh Panchal
//2K20/MC/21

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    vector<vector<int>> data;
    Node *n1, *n2, *n3, *n4;
};

Node *createNode(vector<vector<int>> data){
    Node *node = new Node;
    node->data = data;
    node->n1 = node->n2 = node->n3 = node->n4 = NULL;
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

vector<vector<int>> findSol(vector<vector<int>> start, vector<vector<int>> goal){
    queue<Node*> q;
    Node *root = createNode(start);
    q.push(root);
    int i=0;
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        ++i;
        if(temp->data == goal){
            cout<<"Solution found after checking "<<i<<" states"<<endl;
            cout<<"Goal State Reached"<<endl;
            return temp->data;
        }
        else{
            vector<vector<int>> up = moveUp(temp->data);
            vector<vector<int>> down = moveDown(temp->data);
            vector<vector<int>> left = moveLeft(temp->data);
            vector<vector<int>> right = moveRight(temp->data);
            if(up != temp->data){
                Node *node = createNode(up);
                temp->n1 = node;
                q.push(node);
            }
            if(down != temp->data){
                Node *node = createNode(down);
                temp->n2 = node;
                q.push(node);
            }
            if(left != temp->data){
                Node *node = createNode(left);
                temp->n3 = node;
                q.push(node);
            }
            if(right != temp->data){
                Node *node = createNode(right);
                temp->n4 = node;
                q.push(node);
            }
        }
    }
}

int main(){
    vector<vector<int>> start = {{8,1,3},{4,0,5},{2,7,6}};
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

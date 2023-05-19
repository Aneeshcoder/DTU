//8-Puzzle problem using DFID Strategy
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

bool DFS(Node *root, vector<vector<int>> data){
    if(root == NULL)
        return false;
    if(root->data == data)
        return true;
    return DFS(root->n1, data) || DFS(root->n2, data) || DFS(root->n3, data) || DFS(root->n4, data);    
}

vector<vector<int>> findSol(vector<vector<int>> start, vector<vector<int>> goal){
    queue<Node*> q1, q2;
    Node *root = createNode(start);
    q2.push(root);
    int i=0;
    while(true){
        int j = q2.size();
        for(int k=0; k<j; k++){
            Node *temp = q2.front();
            q2.pop();
            q1.push(temp);    
        }

        while(!q1.empty()){
            Node *temp = q1.front();
            q1.pop();
            vector<vector<int>> up = moveUp(temp->data);
            vector<vector<int>> down = moveDown(temp->data);
            vector<vector<int>> left = moveLeft(temp->data);
            vector<vector<int>> right = moveRight(temp->data);
            if(up != temp->data){
                Node *node = createNode(up);
                temp->n1 = node;
                q2.push(node);
            }
            if(down != temp->data){
                Node *node = createNode(down);
                temp->n2 = node;
                q2.push(node);
            }
            if(left != temp->data){
                Node *node = createNode(left);
                temp->n3 = node;
                q2.push(node);
            }
            if(right != temp->data){
                Node *node = createNode(right);
                temp->n4 = node;
                q2.push(node);
            }
        }

        if(DFS(root, goal)){
            cout<<"Solution found at depth "<<i<<endl;
            cout<<"Goal State Reached"<<endl;
            return goal;
        }
        else
            i++;
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

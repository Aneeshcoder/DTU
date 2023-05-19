//3 SAT Problem using Stochastic Hill Climbing Algorithm
//F = (b V c’) Ʌ (c V d’) Ʌ (b’) Ʌ (a’ V e’) Ʌ (c’ V e) Ʌ (c’ V d’)
//Aneesh Panchal
//2K20/MC/21

#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

struct Node{
    vector<int> data;
    Node *n1, *n2;
    int same, changed;
    int depth;
};

Node *createNode(vector<int> data, int depth){
    Node *node = new Node;
    node->data = data;
    node->same = node->changed = 0;
    node->n1 = node->n2 = NULL;
    node->depth = depth;
    return node;
}

int heuristicValue(vector<int> data){
    int a = data[0], b = data[1], c = data[2], d = data[3], e = data[4];
    int i = b || (!c);
    int ii = c || (!d);
    int iii = !b;
    int iv = (!a) || (!e);
    int v = e || (!c);
    int vi = (!c) || (!d);
    int val = i + ii + iii + iv + v + vi;
    return val;
}

float Probability(int h, int hp){
    int e = exp(-(hp-h)/10);
    float p = (float)1/(1 + e);
    return p;
}

vector<int> NeighbourFunction(vector<int> data, int index){
    data[index] = !data[index];
    return data;
}

vector<int> findSol(vector<int> arr){
    queue<Node*> q;
    Node *root = createNode(arr, 0);
    q.push(root);
    vector<int> same = arr;
    vector<int> changed = arr;
    int hp = heuristicValue(arr);
    int h = heuristicValue(arr);
    int deep = 0;
    float prob;
    while(true){
        Node *temp = q.front();
        q.pop();
        if(heuristicValue(temp->data) == 6){
            cout<<"Goal State Reached"<<endl;
            return temp->data;
        }
        else{
            deep = temp->depth;
            same = temp->data;
            changed = NeighbourFunction(same, deep);
            hp = heuristicValue(same);
            h = heuristicValue(changed);
            prob = Probability(h,hp);
            if(prob >= 0.5){
                temp->n2 = createNode(changed,deep+1);
                temp->n2->changed = 1;
                q.push(temp->n2);
            }
            if(prob <= 0.5){
                temp->n1 = createNode(same,deep+1);
                temp->n1->same = 1;
                q.push(temp->n1);
            }
        }
    }
}

int main(){
    vector<int> init_data = {1,1,1,1,1};
    vector<int> soln = findSol(init_data);
    cout<<endl<<"Initial Data: "<<endl;
    cout<<"a b c d e"<<endl;
    for(int i=0; i<init_data.size(); i++)
        cout<<init_data[i]<<" ";
    cout<<endl<<"Heuristic Value: "<<heuristicValue(init_data)<<endl;
    cout<<endl<<"Solution: "<<endl;
    cout<<"a b c d e"<<endl;
    for(int i=0; i<soln.size(); i++)
        cout<<soln[i]<<" ";
    cout<<endl<<"Heuristic Value: "<<heuristicValue(soln)<<endl<<endl;
    return 0;
}

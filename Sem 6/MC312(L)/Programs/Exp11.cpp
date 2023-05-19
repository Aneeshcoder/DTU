//AND OR Graph problem using AO* algorithm
//Aneesh Panchal
//2K20/MC/21

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<climits>
#include<algorithm>
#include<string>
using namespace std;

map<string,int> costCalc(map<char,int> &H, vector<string> &Condition, int weight=1){
    map<string,int> Updated_cost;
    for(auto i:Condition){
        Updated_cost[i] = 0;
        for(auto k:i){
            Updated_cost[i] += H[k] + weight;
        }
    }
    return Updated_cost;
}

map<char,map<string,int>> Updated_costs(map<char,int> &H, map<char,vector<string>> &Conditions, int weight = 1){
    vector<char> Nodes;
    map<char,map<string,int>> UpdatedC;
    for(auto i:H){
        Nodes.push_back(i.first);
    }
    reverse(Nodes.begin(), Nodes.end());
    for(auto node:Nodes){
        if(Conditions.find(node) == Conditions.end()) continue;
        else{
            UpdatedC[node] = costCalc(H, Conditions[node], weight);
            int minC = INT_MAX;
            for(auto i:UpdatedC[node]){
                minC = min(minC, i.second);
            }
            H[node] = minC;
        }
    }
    return UpdatedC;
}

void printUpdatedC(map<char,map<string,int>> &Updated_cost){
    for(auto i:Updated_cost){
        cout<<i.first<<" -> { ";
        for(auto p:i.second){
            cout<<p.first<<":"<<p.second<<" ";
        }
        cout<<"}\n";
    }
}

void printShortestP(map<char,map<string,int>> &Updated_costs,char start){
    queue<char> Path;
    Path.push(start);
    while(!Path.empty()){
        string next;
        char curr;
        int v = INT_MAX;
        curr = Path.front();
        Path.pop();
        if(!Updated_costs[curr].empty()){
            for(auto i:Updated_costs[curr]){
                if(i.second < v){
                    v = i.second;
                    next = i.first;
                }
            }
        }
        if(v==INT_MAX){
            cout<<curr<<": 0\n";
        }
        else{
            for(auto i:next)
                Path.push(i);
            cout<<curr<<" -> "<<next[0];
            for(int i=1; i<next.size(); i++){
                cout<<" AND "<<next[i];
            }
            cout<<" : " <<v<<endl;
        }
    }
}

int main(){
    map<char,int> HeuristicV {{'A',0},{'B',6},{'C',7},{'D',4},{'E',5},{'F',6},{'G',8},{'H',0},{'I',3},{'J',4},{'K',7},{'L',10},{'M',0},{'N',0},{'O',0},{'P',0},{'Q',9},{'R',10},{'S',0},{'T',0}};
    map<char,vector<string>> Conditions{{'A',{"BC","DE"}},{'B',{"FG","H"}},{'C',{"IJ"}},{'D',{"IJ", "K"}},{'E',{"MN","L"}},{'F',{"O"}},{'G',{"O"}},{'I',{"P"}},{'J',{"P"}},{'K',{"Q","R","L"}},{'L',{"T"}},{'Q',{"R","S"}},{'R',{"T"}}};
    cout<<endl;
    map<char,map<string,int>> UpdatedC = Updated_costs(HeuristicV,Conditions);
    printUpdatedC(UpdatedC);
    cout<<"\nShortest Path:\n";
    printShortestP(UpdatedC,'A');
    return 0;
}

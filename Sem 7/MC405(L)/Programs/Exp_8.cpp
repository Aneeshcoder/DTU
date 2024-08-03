// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<int> find_Path(vector<vector<int>> adjacency, int source, int sink, vector<bool> visited){
    if(source==sink){
        vector<int> path;
        path.push_back(source);
        return path;
    }
    for(int i=0;i<adjacency[source].size();i++){
        if(adjacency[source][i] && !visited[i]){
            visited[i] = true;
            vector<int> temp = find_Path(adjacency, i, sink, visited);
            if(temp.size()){
                temp.push_back(source);
                return temp;
            }
            visited[i] = false;
        }
    }
    return vector<int>();
}

void FordFulkerson(vector<vector<int>> adjacency){
    int len = adjacency.size();
    vector<vector<int>> changed = adjacency;
    vector<vector<int>> network(len,vector<int>(len,0));
    while(true){
        vector<bool> visited(len,false);
        vector<int> path = find_Path(changed,0,7,visited);
        if(path.size()==0)
            break;
        int min = INT_MAX;
        reverse(path.begin(), path.end());
        for(int i=0;i<path.size()-1;++i){
            int val = changed[path[i]][path[i+1]];
            if(val<min)
                min = val;
        }
        for(int i=0;i<path.size()-1;++i){
            changed[path[i]][path[i+1]] = changed[path[i]][path[i+1]] - min;
            changed[path[i+1]][path[i]] = changed[path[i+1]][path[i]] + min;
            network[path[i]][path[i+1]] = network[path[i]][path[i+1]] + min;
        }
    }

    cout<<"Flow Network"<<endl;
    for(int i=0;i<network.size();i++){
        for(int j=0;j<network.size();j++)
            cout<<network[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    int max_flow=0;
    for(int i=0;i<len;++i){
        max_flow = max_flow + network[i][len-1];
    }
    cout<<"Maximum Flow: "<<max_flow<<endl<<endl;
}

int main(){
    vector<vector<int>> adjacency = {{0,10,5,15,0,0,0,0},{0,0,4,0,9,14,0,0},
                                    {0,0,0,4,0,8,0,0},{0,0,0,0,0,0,16,0},
                                    {0,0,0,0,0,15,0,10},{0,0,0,0,0,0,15,10},
                                    {0,0,6,0,0,0,0,10},{0,0,0,0,0,0,0,0}};
    cout<<endl<<"Initial Adjacency Matrix: "<<endl;
    for(int i=0;i<adjacency.size();i++){
        for(int j=0;j<adjacency.size();j++)
            cout<<adjacency[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    FordFulkerson(adjacency);
    return 0;
}

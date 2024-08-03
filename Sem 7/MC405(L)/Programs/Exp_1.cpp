// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
#include<vector>
using namespace std;

void find_degree(vector<vector<int>> adjacency){
    int len = adjacency.size();
    vector<int> edges(len,0);
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            edges[i] = edges[i] + adjacency[i][j];
    vector<int> solution = {0,0,0};
    int tot_edges = 0;
    for(int i=0;i<len;i++){
        tot_edges = tot_edges + edges[i];
        if(edges[i]%2!=0)
            ++solution[0];
        else
            ++solution[1];
    }
    solution[2] = solution[0]+solution[1];
    int total_edges = tot_edges/2;
    cout<<endl<<"Odd vertices: "<<solution[0]<<endl;
    cout<<"Even vertices: "<<solution[1]<<endl;
    cout<<"Total vertices: "<<solution[2]<<endl<<endl;
    cout<<"Total Number of Edges: "<<total_edges<<endl<<endl;

}

int main(){
    vector<vector<int>> adjacency = {{0,1,0,0,1},{1,0,1,1,0},{0,1,0,1,1},{0,1,1,0,0},{1,0,1,0,0}};
    for(int i=0;i<adjacency.size();i++){
        for(int j=0;j<adjacency.size();j++)
            cout<<adjacency[i][j]<<" ";
        cout<<endl;
    }
    find_degree(adjacency);
    return 0;
}

// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
#include<vector>
using namespace std;

void union_intersection(vector<vector<int>> graph_one, vector<vector<int>> graph_two){
    int len = graph_one.size();
    vector<vector<int>> union_graph(len,vector<int>(len,0));
    vector<vector<int>> intersection_graph(len,vector<int>(len,0));
    vector<vector<int>> ring_sum(len,vector<int>(len,0));
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(graph_one[i][j]==graph_two[i][j]){
                intersection_graph[i][j] = graph_one[i][j];
                union_graph[i][j] = graph_one[i][j];
            }
            else{
                if(graph_one[i][j]==1 || graph_two[i][j]==1)
                    union_graph[i][j] = 1;
                intersection_graph[i][j] = 0;
            }
            ring_sum[i][j] = union_graph[i][j]-intersection_graph[i][j];
        }
    }
    cout<<"Union Graph: "<<endl;
    for(int i=0;i<union_graph.size();i++){
        for(int j=0;j<union_graph.size();j++)
            cout<<union_graph[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"Intersection Graph: "<<endl;
    for(int i=0;i<intersection_graph.size();i++){
        for(int j=0;j<intersection_graph.size();j++)
            cout<<intersection_graph[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"Ring Sum Graph: "<<endl;
    for(int i=0;i<ring_sum.size();i++){
        for(int j=0;j<ring_sum.size();j++)
            cout<<ring_sum[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> graph_one = {{0,1,1,0,0},{1,0,1,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    vector<vector<int>> graph_two = {{0,0,0,0,0},{0,0,1,0,1},{0,1,0,1,0},{0,0,1,0,1},{0,1,0,1,0}};
    cout<<"Graph I: "<<endl;
    for(int i=0;i<graph_one.size();i++){
        for(int j=0;j<graph_one.size();j++)
            cout<<graph_one[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"Graph II: "<<endl;
    for(int i=0;i<graph_two.size();i++){
        for(int j=0;j<graph_two.size();j++)
            cout<<graph_two[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    union_intersection(graph_one,graph_two);
    return 0;
}

// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void BellmanFord(vector<vector<int>> adjacency, int source){
    int len = adjacency.size();
    vector<int> distance(len,INT_MAX);
    distance[source] = 0;
    for(int i=0;i<len-1;i++)
        for(int j=0;j<len;j++)
            for(int k=0;k<len;k++)
                if(adjacency[j][k]!=0 && distance[j]!=INT_MAX && distance[j]+adjacency[j][k]<distance[k])
                    distance[k]=distance[j]+adjacency[j][k];
    cout<<"Final Distance Matrix: "<<endl;
    for(int i=0;i<len;i++)
        cout<<"To vertex: "<<i<<" with Distance: "<<distance[i]<<endl;
}

int main(){
    vector<vector<int>> adjacency = {{0,10,0,0,0,8}, {0,0,0,2,0,0},
                                    {0,1,0,0,0,0}, {0,0,-2,0,0,0},
                                    {0,-4,0,-1,0,0}, {0,0,0,0,1,0}};
    cout<<endl<<"Initial Adjacency Matrix: "<<endl;
    for(int i=0;i<adjacency.size();i++){
        for(int j=0;j<adjacency.size();j++)
            cout<<adjacency[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    int source = 0;
    BellmanFord(adjacency, source);
    cout<<endl;
    return 0;
}

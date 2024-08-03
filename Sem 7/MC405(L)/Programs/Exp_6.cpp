// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> indices(vector<vector<int>> adjacency, vector<bool> selected, int len){
    vector<int> index(2,len);
    int min = INT_MAX;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(adjacency[i][j]>0 && adjacency[i][j]<min && selected[i]==true && selected[j]==false){
                min = adjacency[i][j];
                index[0] = i;
                index[1] = j;
            }
        }
    }
    return index;
}

vector<int> initial(vector<vector<int>> adjacency, int len){
    vector<int> index(2,len);
    int min = INT_MAX;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(adjacency[i][j]>0 && adjacency[i][j]<min){
                min = adjacency[i][j];
                index[0] = i;
                index[1] = j;
            }
        }
    }
    return index;
}

void Prims(vector<vector<int>> adjacency){
    int len = adjacency.size();
    vector<int> index(2,INT_MAX);
    vector<bool> selected(len,false);
    vector<vector<int>> selected_edges(len,vector<int>(len,0));
    int x = 0, y = 0, count = 0, iter = 1;
    while(true){
        if(iter == 1)
            index = initial(adjacency,len);
        else    
            index = indices(adjacency,selected,len);
        x = index[0];
        y = index[1];
        selected[x] = true;
        selected[y] = true;
        selected_edges[x][y] = adjacency[x][y];
        selected_edges[y][x] = adjacency[y][x];

        ++iter;
        for(int i=0;i<len;++i)
            if(selected[i]==true)
                ++count;
        if(count==len)
            break;
        else
            count = 0;
    }

    cout<<endl<<"MST using Prims Algorithm: "<<endl;
    for(int i=0;i<len;i++){
        for(int j=0;j<selected_edges.size();j++)
            cout<<selected_edges[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    int val = 0;
    for(int i=0;i<selected_edges.size();i++)
        for(int j=0;j<selected_edges.size();j++)
            val = val + selected_edges[i][j];
    cout<<"Total Cost of MST: "<<val/2<<endl<<endl;
}

int main(){
    /*
    vector<vector<int>> adjacency = {{0,2,0,0,3,0,0,0,0,0,0,0}, {2,0,3,0,0,1,0,0,0,0,0,0},
                                    {0,3,0,1,0,0,2,0,0,0,0,0}, {0,0,1,0,0,0,0,5,0,0,0,0},
                                    {3,0,0,0,0,4,0,0,4,0,0,0}, {0,1,0,0,4,0,3,0,0,2,0,0},
                                    {0,0,2,0,0,3,0,3,0,0,4,0}, {0,0,0,5,0,0,3,0,0,0,0,3},
                                    {0,0,0,0,4,0,0,0,0,3,0,0}, {0,0,0,0,0,2,0,0,3,0,3,0},
                                    {0,0,0,0,0,0,4,0,0,3,0,1}, {0,0,0,0,0,0,0,3,0,0,1,0}};
    */
    vector<vector<int>> adjacency = {{0,2,4,4},{2,0,3,2},{4,3,0,1},{4,2,1,0}};
    cout<<endl<<"Initial Adjacency Matrix: "<<endl;
    for(int i=0;i<adjacency.size();i++){
        for(int j=0;j<adjacency.size();j++)
            cout<<adjacency[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    Prims(adjacency);
    return 0;
}

// Aneesh Panchal 2K20/MC/21

#include<iostream>
#include<vector>
using namespace std;

void max_match(vector<vector<int>> &adjacency, int m){
    int len = adjacency.size();
    vector<bool> visited(len);
    vector<int> match(len, -1);
    int count = 0;
    
    for(int i=0; i<m; i++){
        visited.assign(len, false);
        bool matched = false;
        for (int adjacentNode=0; adjacentNode<len && !matched; adjacentNode++){
            if(adjacency[i][adjacentNode] && !visited[adjacentNode]){
                visited[adjacentNode] = true;
                if(match[adjacentNode]==-1){
                    match[adjacentNode]=i;
                    matched = true;
                } 
                else{
                    for(int otherNode=0; otherNode<len; otherNode++){
                        if(adjacency[match[adjacentNode]][otherNode] && !visited[otherNode]){
                            visited[otherNode] = true;
                            if(match[otherNode]==-1 || match[otherNode]==i){
                                match[otherNode] = match[adjacentNode];
                                match[adjacentNode] = i;
                                matched = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(matched)
            count++;
    }

    vector<bool> checked(len,false);
    cout<<endl;
    cout<<"Maximum matching is "<<count<<endl;
    cout<<endl;
    cout<<"Edges are: "<<endl;
    for(int i=0;i<len;i++)
        if(match[i] != -1 && !checked[i]){
            cout<<match[i]+1<<" "<<i+1<<endl;
            checked[i] = true;
            checked[match[i]] = true;
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> adjacency = {{0,0,0,0,1,1,1,1},{0,0,0,0,1,1,1,1},{0,0,0,0,1,1,1,1},{0,0,0,0,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};
    cout<<endl;
    cout<<"Adjacency matrix is: "<<endl;
    for(int i=0; i<adjacency.size(); i++){
        for(int j=0; j<adjacency.size(); j++)
            cout<<adjacency[i][j]<<" ";
        cout<<endl;
    }
    max_match(adjacency, 4);
    return 0;
}

/*

    auto canMatch = [&](int u, auto &self) -> bool{
        for(int v=0; v<len; v++){
            if(adjacency[u][v] && !visited[v]){
                visited[v] = true;
                if(match[v]==-1 || self(match[v],self)){
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    };

    for(int i=0; i<m; i++){
        visited.assign(len, false);
        if(canMatch(i, canMatch)){
            count++;
        }
    }

*/
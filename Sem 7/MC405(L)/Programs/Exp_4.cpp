// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void FloydWarshall(vector<vector<int>> adjacency){
    int len = adjacency.size();
    vector<vector<int>> temp = adjacency;
    vector<vector<int>> updated(len,vector<int>(len,0));
    for(int count=0;count<len;++count){
        for(int i=0;i<len;++i)
            for(int j=0;j<len;++j){
                if(i==count || j==count || temp[i][count]==INT_MAX || temp[count][j]==INT_MAX)
                    updated[i][j] = temp[i][j];
                else{
                    if(temp[i][count] + temp[count][j] < temp[i][j])
                        updated[i][j] = temp[i][count] + temp[count][j];
                    else
                        updated[i][j] = temp[i][j];
                }
            }                    
        temp = updated;
    }
    
    cout<<"Final Minimum Distance Matrix: "<<endl;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++)
            if (temp[i][j]==INT_MAX)
                cout<<"inf"<<" ";
            else
                cout<<temp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main(){
//    vector<vector<int>> adjacency = {{0,3,8,INT_MAX,-4},{INT_MAX,0,INT_MAX,1,7},{INT_MAX,4,0,INT_MAX,INT_MAX},{2,INT_MAX,-5,0,INT_MAX},{INT_MAX,INT_MAX,INT_MAX,6,0}};
    vector<vector<int>> adjacency = {{0,5,INT_MAX,10},{INT_MAX,0,3,INT_MAX},{INT_MAX,INT_MAX,0,1},{INT_MAX,INT_MAX,INT_MAX,0}};
    cout<<endl<<"Initial Adjacency Matrix: "<<endl;
    for(int i=0;i<adjacency.size();i++){
        for(int j=0;j<adjacency.size();j++){
            if(adjacency[i][j]==INT_MAX)
                cout<<"inf"<<" ";
            else
                cout<<adjacency[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    FloydWarshall(adjacency);
    return 0;
}

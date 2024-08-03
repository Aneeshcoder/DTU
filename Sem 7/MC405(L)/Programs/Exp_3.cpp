// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int min_dist(vector<int> distance, vector<bool> visited){
	int len = distance.size();
    int min = INT_MAX;
    int index = INT_MAX;          
	for(int i=0;i<len;i++)
		if(visited[i]==false && distance[i]<=min){
			min = distance[i];
			index = i;
		}
	return index;
}

void Dijkstras(vector<vector<int>> adjacency, int source){
    int len = adjacency.size();
    vector<int> distance(len,INT_MAX);
    vector<bool> visited(len,false);
	distance[source] = 0;
	for(int count=0;count<len;count++){
		int min_index = min_dist(distance,visited);
		visited[min_index] = true;
		for(int i=0;i<len;i++)
			if(!visited[i] && adjacency[min_index][i] && distance[min_index]!=INT_MAX && distance[min_index]+adjacency[min_index][i]<distance[i])
				distance[i]=distance[min_index]+adjacency[min_index][i];
	}
    cout<<"Source Vertex: "<<source<<endl;
	for(int i=0;i<len;i++)
		cout<<"To vertex: "<<i<<" with Distance: "<<distance[i]<<endl;
    cout<<endl;
}


int main(){
    /*
    vector<vector<int>> adjacency = {{0,8,2,5,0,0,0,0}, {8,0,0,2,0,13,0,0},
                                    {2,0,0,2,5,0,0,0}, {5,2,2,0,1,6,3,0},
                                    {0,0,5,1,0,0,1,0}, {0,13,0,6,0,0,3,3},
                                    {0,0,0,3,1,2,0,6}, {0,0,0,0,0,3,6,0}};
    */
    //vector<vector<int>> adjacency = {{1,2,2,4},{1,4,2,0},{3,1,0,3},{4,3,1,2}};
    vector<vector<int>> adjacency = {{0,2,2,4},{1,0,2,0},{3,1,0,3},{4,3,1,0}};
    cout<<endl<<"Initial Adjacency Matrix: "<<endl;
    for(int i=0;i<adjacency.size();i++){
        for(int j=0;j<adjacency.size();j++)
            cout<<adjacency[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    Dijkstras(adjacency,1);
    return 0;
}

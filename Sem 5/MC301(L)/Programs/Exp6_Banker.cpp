#include<iostream>
#include<vector>
using namespace std;

int kval(vector<vector<int>> req, vector<int> available, int i){
    int k = 0;
    for(int m=0;m<available.size();++m)
        if(req[i][m]<=available[m])
            ++k;
    return k;
}

bool deadlock(vector<vector<int>> req, vector<int> available, vector<int> done){
    bool dead = true;
    int k=0;
    for(int i=0;i<req.size();++i){
        k = kval(req,available,i);
        if(done[i]==false && k==available.size()){
            dead = false;
            break;
        }
        else 
            continue;
    }
    return dead;
}

vector<int> allocation(vector<vector<int>> alloc,vector<int> available, int i){
    for(int m=0;m<available.size();++m)
        available[m] = alloc[i][m] + available[m];
    return available;
}

vector<int> safeseq(vector<vector<int>> alloc, vector<vector<int>> req, vector<int> available){
    vector<int> safe(req.size(),0);
    vector<int> done(req.size(),false);
    int j=0;
    for(int i=0;i<req.size();++i){
        int k=0;
        k = kval(req,available,i);
        if(done[i]==false && k==available.size()){
            safe[j] = i;
            done[i] = true;
            available = allocation(alloc,available,i);
            ++j;
        }
        if(j==req.size())
            break;
        if(i==req.size()-1){
            bool dead = deadlock(req,available,done);
            if(dead){
                safe[0] = -1;
                break;
            }
            i=0;
        }
    }
    return safe;
}

int main(){
    vector<int> available = {3,3,0};
    vector<vector<int>> alloc = {{1,0,1},{1,1,2},{1,0,3},{2,0,0}};
    vector<vector<int>> maximum = {{4,3,1},{2,1,4},{1,3,3},{5,4,1}};
    vector<vector<int>> req(alloc.size(),vector<int>(alloc[0].size(),0));
    for(int i=0;i<alloc.size();++i){
        for(int j=0;j<alloc[0].size();++j)
            req[i][j] = maximum[i][j] - alloc[i][j];    
    }
    vector<int> safe = safeseq(alloc,req,available);
    
    if(safe[0]==-1)
        cout<<endl<<"Deadlock Exists !!!"<<endl;
    else{
        cout<<endl<<"No Deadlock !!!"<<endl<<endl<<"Safe Sequence is:"<<endl;
        for(int i=0;i<safe.size();++i)
            cout<<safe[i]<<endl;
        cout<<endl;
    }
    return 0;
}

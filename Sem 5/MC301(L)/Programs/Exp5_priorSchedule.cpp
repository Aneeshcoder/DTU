#include<iostream>
#include<vector>
using namespace std;

int priority(vector<bool> done, vector<int> AT, vector<int> PT, int t){
    int p = -1;
    for(int i=0;i<AT.size();++i){
        if(p==-1 && done[i]==false)
            p=i;
        else if((AT[i]<=t) && (done[i]==false) && (PT[i]<PT[p]))
            p=i;
    }
    return p;
}

void tut(vector<int> WT, vector<int> ET){
    vector<int> TUT(WT.size(),0);
    float avgtut = 0;
    for(int i=0;i<WT.size();i++){
        TUT[i]=WT[i]+ET[i];
        avgtut = avgtut + TUT[i];
    }
    avgtut = float(avgtut/float(WT.size()));
    cout<<"Average Turn Around Time: "<<avgtut<<endl;
}

void wt(vector<int> AT, vector<int> ET, vector<int> PT){
    vector<int> WT(AT.size(),0);
    vector<bool> done(AT.size(),false);
    int t = AT[0];
    for(int i=0;i<AT.size();i++){
        int index = priority(done,AT,PT,t);
        WT[index] = t - AT[index];
        t = t + ET[index];
        done[index] = true;
    }
    float avgwt = 0;
    for(int i=0;i<AT.size();i++)
        avgwt = avgwt + WT[i];
    avgwt = float(avgwt/float(WT.size()));
    cout<<"Average Waiting Time: "<<avgwt<<endl;
    tut(WT,ET);
}

int main(){
    vector<int> AT = {1,4,4,6};
    vector<int> ET = {10,3,5,2};
    vector<int> PT = {2,3,1,4};
    cout<<endl;
    wt(AT,ET,PT);
    cout<<endl;
    return 0;
}

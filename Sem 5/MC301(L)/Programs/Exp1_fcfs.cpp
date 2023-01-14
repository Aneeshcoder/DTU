#include<iostream>
#include<vector>
using namespace std;

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

void wt(vector<int> AT, vector<int> ET){
    vector<int> WT(AT.size(),0);
    int newET = AT[0];
    for(int i=1;i<AT.size();i++){
        newET = ET[i-1] + newET;
        WT[i] = newET - AT[i];
    }
    float avgwt = 0;
    for(int i=0;i<AT.size();i++)
        avgwt = avgwt + WT[i];
    avgwt = float(avgwt/float(WT.size()));
    cout<<"Average Waiting Time: "<<avgwt<<endl;
    tut(WT,ET);
}

int main(){
    vector<int> AT = {1,2,4,6};
    vector<int> ET = {10,3,5,2};
    cout<<endl;
    wt(AT,ET);
    cout<<endl;
    return 0;
}

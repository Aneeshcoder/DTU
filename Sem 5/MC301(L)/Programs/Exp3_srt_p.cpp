#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void tut(vector<int> BT,vector<int> WT){
    vector<int> TUT(WT.size(),0);
    for(int i=0;i<WT.size();i++)
        TUT[i] = BT[i] + WT[i];
    float avgtut = 0;
    for(int i=0;i<WT.size();i++)
        avgtut = avgtut + TUT[i];
    avgtut = float(avgtut/float(WT.size()));
    cout<<"Average Turn Around Time: "<<avgtut<<endl;
}

void wt(vector<int> AT,vector<int> BT){
    vector<int> WT(AT.size(),0);
    vector<int> RT=BT;  
    int complete = 0, t = 0, minm = INT_MAX;
    int index = 0, finish_time;
    bool check = false;
    while(complete != AT.size()){
        for(int j=0;j<AT.size();j++){
            if((AT[j]<=t) && (RT[j]<minm) && RT[j]>0){
                minm = RT[j];
                index = j;
                check = true;
            }
        }  
        if(check == false){
            t++;
            continue;
        }
        RT[index]--;
        minm = RT[index];
        if(minm == 0)
            minm = INT_MAX;
        if(RT[index] == 0){
            complete++;
            check = false;
            finish_time = t + 1;
            WT[index] = finish_time - BT[index] - AT[index];
            if(WT[index]<0)
                WT[index] = 0;
        }
        t++;
    }
    float avgwt = 0;
    for(int i=0;i<AT.size();i++)
        avgwt = avgwt + WT[i];
    avgwt = float(avgwt/float(WT.size()));
    cout<<"Average Waiting Time: "<<avgwt<<endl;
    tut(BT,WT);
}

int main(){  
    vector<int> AT = {0,1,2,3,4};
    vector<int> BT = {10,1,2,1,5};
    cout<<endl;
    wt(AT,BT);
    cout<<endl;
	return 0;
}

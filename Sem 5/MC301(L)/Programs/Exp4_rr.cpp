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

void wt(vector<int> AT, vector<int> ET,int quant){
    vector<int> BT = ET;
    vector<int> WT(AT.size(),0);
    int t = AT[0];

    while(true){
        bool flag = true;
        for(int i=0;i<AT.size();++i)
            if(BT[i]>0){
                flag = false;
                if(BT[i]>quant){
                    t = t + quant;
                    BT[i] = BT[i] - quant;
                    AT[i] = AT[i] + quant;
                }
                else{
                    t = t + BT[i];
                    WT[i] = t - AT[i] - BT[i];
                    BT[i] = 0;
                }
            }
        if(flag)
            break;
    }
    float avgwt = 0;
    for(int i=0;i<AT.size();i++)
        avgwt = avgwt + WT[i];
    avgwt = float(avgwt/float(WT.size()));
    cout<<"Average Waiting Time: "<<avgwt<<endl;
    tut(WT,ET);
}

int main(){
    int quant = 2;
    vector<int> AT = {0,1,2,3,4,6};
    vector<int> ET = {4,5,2,1,6,3};
    cout<<endl;
    wt(AT,ET,quant);
    cout<<endl;
    return 0;
}

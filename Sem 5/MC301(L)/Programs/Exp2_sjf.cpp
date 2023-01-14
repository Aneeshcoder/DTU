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

int minarr(vector<int> AT ,vector<int> ET, vector<bool> done, int n){
    int min = 0;
    int doi = 0;
    if(n==0)
        for(int i=0;AT[0]!=n;++i)
            ++n;
    for(int i=0;i<ET.size();i++)
        if(done[i]==false){
            if(n>=AT[i])
                if(ET[i]<ET[min])
                    min = i;
            else if(doi==0 && n<AT[i]){
                n = AT[i];
                min = i;
                for(int j=i;j<ET.size()-i;++j){
                    if(done[j]==false && ET[j]<ET[min])
                        min = j;
                }
                break;
            }
            ++doi;
        }
    return min;
}

void wt(vector<int> AT, vector<int> ET){
    vector<int> WT(AT.size(),0);
    vector<bool> done(AT.size(),false);
    int newET = 0;
    int index = 0;
    for(int i=0;i<AT.size();i++){
        index = minarr(AT,ET,done,newET);
        if(i==0){
            newET = AT[index] + ET[index];
            WT[index] = 0;
        }
        else{
            WT[index] = newET - AT[index];
            newET = ET[index] + newET;
            if(WT[index]<=0){
                newET = newET - WT[index];
                WT[index]=0; 
            }
        }
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
    vector<int> AT = {1,2,4,6};
    vector<int> ET = {10,3,5,2};
    cout<<endl;
    wt(AT,ET);
    cout<<endl;
    return 0;
}

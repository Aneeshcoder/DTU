#include<iostream>
#include<vector>
using namespace std;

int total_head_movement(vector<int> Track, int head){
    int total = 0;
    cout<<head;
    for(int i=0;i<Track.size();i++){
        cout<<" -> "<<Track[i];
        total = total + abs(head-Track[i]);
        head = Track[i];
    }
    cout<<endl<<endl;
    return total;
}

int main(){
    int head = 345;
    vector<int> Track = {123, 874, 692, 475, 105, 376};
    cout<<endl;
    cout<<"FCFS Head Movements: ";
    cout<<"FCFS Total Head Movement: "<<total_head_movement(Track,head)<<endl;
    cout<<endl;
    return 0;
}

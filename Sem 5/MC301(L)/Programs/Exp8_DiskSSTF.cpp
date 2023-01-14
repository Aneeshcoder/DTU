#include<iostream>
#include<vector>
using namespace std;

vector<int> SSTF(vector<int> Track, int head){
    vector<int> SSTF(Track.size(),0);
    vector<bool> done(Track.size(),false);
    for(int i=0;i<Track.size();i++){
        int min = INT16_MAX;
        int index = 0;
        for(int j=0;j<Track.size();j++)
            if(done[j]==false && abs(head-Track[j])<min){
                min = abs(head-Track[j]);
                index = j;
            }
        SSTF[i] = Track[index];
        done[index] = true;
        head = Track[index];
    }
    return SSTF;
}

int total_head_movement(vector<int> Track, int head){
    int total = 0;
    for(int i=0;i<Track.size();i++){
        total = total + abs(head-Track[i]);
        head = Track[i];
    }
    cout<<endl<<endl;
    return total;
}

int main(){
    int head = 345;
    vector<int> Track = {123, 874, 692, 475, 105, 376};
    vector<int> SSTF_track = SSTF(Track,head);
    cout<<endl;
    cout<<"SSTF Head Movements: ";
    cout<<head;
    for(int i=0;i<SSTF_track.size();i++)
        cout<<" -> "<<SSTF_track[i];
    cout<<"SSTF Total Head Movement: "<<total_head_movement(SSTF_track,head)<<endl;
    cout<<endl;
    return 0;
}

//3 SAT Problem using Variable Neighbourhood Decent
//F = (b V c’) Ʌ (c V d’) Ʌ (b’) Ʌ (a’ V e’) Ʌ (c’ V e) Ʌ (c’ V d’)
//Aneesh Panchal
//2K20/MC/21

#include<iostream>
#include<vector>
using namespace std;
vector<int> num;

int heuristicValue(vector<int> data){
    int a = data[0], b = data[1], c = data[2], d = data[3], e = data[4];
    int i = b || (!c);
    int ii = c || (!d);
    int iii = !b;
    int iv = (!a) || (!e);
    int v = e || (!c);
    int vi = (!c) || (!d);
    int val = i + ii + iii + iv + v + vi;
    return val;
}

vector<int> NeighbourFunction(vector<int> data, int k){
    vector<int> temp = data;
    vector<int> sol = data;
    int a = k%10;
    int b = (k/10)%10;
    int c = (k/100)%10;
    int d = (k/1000)%10;
    int e = (k/10000)%10;
    int h = heuristicValue(data);
    int ht = h;

    if(a==1 || b==1 || c==1 || d==1 || e==1){
        for(int i=0; i<5; i++){
            temp = data;
            temp[i] = !temp[i];
            ht = heuristicValue(temp);
            if(ht > h){
                sol = temp;
                h = ht;
            }
        }
    }

    if(a==2 || b==2 || c==2 || d==2 || e==2){
        for(int i=0; i<5; i++){
            for(int j=i+1; j<5; j++){
                temp = data;
                temp[i] = !temp[i];
                temp[j] = !temp[j];
                ht = heuristicValue(temp);
                if(ht > h){
                    sol = temp;
                    h = ht;
                }
            }
        }
    }

    if(a==3 || b==3 || c==3 || d==3 || e==3){
        for(int i=0; i<5; i++){
            for(int j=i+1; j<5; j++){
                for(int k=j+1; k<5; k++){
                    temp = data;
                    temp[i] = !temp[i];
                    temp[j] = !temp[j];
                    temp[k] = !temp[k];
                    ht = heuristicValue(temp);
                    if(ht > h){
                        sol = temp;
                        h = ht;
                    }
                }
            }
        }
    }

    if(a==4 || b==4 || c==4 || d==4 || e==4){
        for(int i=0; i<5; ++i){
            temp = data;
            for(int j=0; j<5; ++j){
                if(i==j)
                    continue;
                else
                    temp[j] = !temp[j];
            }
            ht = heuristicValue(temp);
            if(ht > h){
                sol = temp;
                h = ht;
            }
        }
    }

    if(a==5 || b==5 || c==5 || d==5 || e==5){
        temp = data;
        temp[0] = !temp[0];
        temp[1] = !temp[1];
        temp[2] = !temp[2];
        temp[3] = !temp[3];
        temp[4] = !temp[4];
        ht = heuristicValue(temp);
        if(ht > h){
            sol = temp;
            h = ht;
        }
    }
    return sol;
}

void Combi(vector<int> vect, int reqLen, int start, int currLen, bool check[], int last){
    int x = 0;
    if(currLen > reqLen)
        return;
    else if(currLen == reqLen){
        for(int i=0; i<last; i++){
            if(check[i] == true){
                x = vect[i] + 10*x;
            }
        }
        num.push_back(x);    
        return;
    }
    if(start==last)
        return;
    check[start] = true;
    Combi(vect, reqLen, start+1, currLen+1, check, last);
    check[start] = false;
    Combi(vect, reqLen, start+1, currLen, check, last);
}

vector<int> findSol(vector<int> data){  
    vector<int> index = {1,2,3,4,5};
    int n = data.size();
    int k = 1;
    bool check[5];
    for(int i=0; i<data.size(); i++)
        check[i] = false;
    while(true){
        Combi(index, k, 0, 0, check, n);
        for(int i=0; i<num.size(); i++){
            data = NeighbourFunction(data, num[i]);
            if(heuristicValue(data) == 6)
                return data;
        }
        num.clear();
        ++k;
    }
    return data;
}

int main(){
    vector<int> init_data = {1,1,1,1,1};
    vector<int> soln = findSol(init_data);
    cout<<endl<<"Initial Data: "<<endl;
    cout<<"a b c d e"<<endl;
    for(int i=0; i<init_data.size(); i++)
        cout<<init_data[i]<<" ";
    cout<<endl<<"Heuristic Value: "<<heuristicValue(init_data)<<endl;
    cout<<endl<<"Solution: "<<endl;
    cout<<"a b c d e"<<endl;
    for(int i=0; i<soln.size(); i++)
        cout<<soln[i]<<" ";
    cout<<endl<<"Heuristic Value: "<<heuristicValue(soln)<<endl<<endl;
    return 0;
}

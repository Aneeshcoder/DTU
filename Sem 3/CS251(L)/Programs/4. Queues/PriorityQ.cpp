#include<iostream>
using namespace std;

#define prior_len 5
#define len 5
class PriorityQueue
{
    public:
        int arr[prior_len][len]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int front_rear[prior_len][2]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    void enqueue(int element,int priority)
    {
        if(front_rear[priority][0]==(front_rear[priority][1]+1) || front_rear[priority][0]==(len-front_rear[priority][1]-1))
        {
            cout<<"Overflow"<<endl;
            return;
        }
        
        else
        {
            if(front_rear[priority][0]==-1)
            {
                front_rear[priority][0]=0;
                front_rear[priority][1]=0;
            }
            
            else if((front_rear[priority][1]==(len-1)) && (front_rear[priority][0]!=0))
            {
                front_rear[priority][1]=0;
            }
            
            else
            {
                ++front_rear[priority][1];
            }
            arr[priority][front_rear[priority][1]]=element;
        }
    }
 
    void dequeue()
    {
        for(int i=0;i<prior_len;++i)
        {
            if(front_rear[i][0]!=-1)
            {
                if(front_rear[i][0]==front_rear[i][1])
                {
                    arr[i][front_rear[i][0]]=-1;
                    front_rear[i][0]=-1;
                    front_rear[i][1]=-1;
                }
            
                else if(front_rear[i][0]==(len-1))
                {
                    arr[i][front_rear[i][0]]=-1;
                    front_rear[i][0]=0;
                }
            
                else 
                {
                    arr[i][front_rear[i][0]]=-1;
                    ++front_rear[i][0];
                }
                return;
            }
        }

        cout<<"Underflow"<<endl;
            return;
    }

    void show()
    {
        cout<<endl;
        for(int i=0;i<prior_len;++i)
        {
            for(int j=0;j<len;++j)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }

};

int main()
{
    cout<<"1 have highest priority"<<endl<<"5 have lowest priority"<<endl;
    
    PriorityQueue PriorQ;
    int element,priority,operations,opr;
    
    cout<<"No of operations want to perform: ";
    cin>>operations;
    cout<<endl;

    for(int i=0;i<operations;++i)
    {
        cout<<"Operation you want :"<<endl<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Show()"<<endl;
        cin>>opr;
        if(opr==1)
        {
            cout<<"Please Enter the element and the priority: ";
            cin>>element>>priority;
            if(priority<=5 && priority>0)
                PriorQ.enqueue(element,priority-1);
            else
            {
                cout<<"Please Enter the right priority"<<endl;
                --i;
                continue;
            }
        }   
        else if(opr==2)
        {
            PriorQ.dequeue();
        }   
        else if(opr==3)
        {
            PriorQ.show();
        }  
        else
        {
            cout<<"Wrong Operation"<<endl;
            --i;
        }
    }
    return 0;
}
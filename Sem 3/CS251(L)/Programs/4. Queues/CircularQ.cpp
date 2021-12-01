#include<iostream>
using namespace std;
 
#define len 5
class CircularQueue
{
    public:
        int arr[len];
        int front=-1;
        int rear=-1;
    
    void enqueue(int element)
    {
        if(front==(rear+1) || front==(len-rear-1))
        {
            cout<<"Overflow"<<endl;
            return;
        }
        
        else
        {
            if(front==-1)
            {
                front=0;
                rear=0;
            }
            
            else if((rear==(len-1)) && (front!=0))
            {
                rear=0;
            }
            
            else
            {
                ++rear;
            }
            arr[rear]=element;
        }
    }
 
    void dequeue()
    {
        if(front==-1)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        
        else
        {
            if(front==rear)
            {
                arr[front]=-1;
                front=-1;
                rear=-1;
            }
            
            else if(front==(len-1))
            {
                arr[front]=-1;
                front=0;
            }
            
            else 
            {
                arr[front]=-1;
                ++front;
            }
        }
    }

    int front_index(){
        return front;
    }

    int rear_index(){
        return rear;
    }

    int front_element(){
        return arr[front];
    }

    int rear_element(){
        return arr[rear];
    }

    void show()
    {
        cout<<endl;
        for(int i=0;i<len;++i)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl<<endl;
    }
};

int main()
{
    CircularQueue array;

    cout<<array.front_index()<<" "<<array.rear_index()<<endl;
    array.enqueue(1);
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.enqueue(2);
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.enqueue(3);
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.enqueue(4);
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.enqueue(5);
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.enqueue(6);
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    cout<<array.front_index()<<" "<<array.rear_index()<<endl;

    array.show();

    cout<<array.front_index()<<" "<<array.rear_index()<<endl;
    array.dequeue();
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.dequeue();
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.enqueue(6);
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.enqueue(7);
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    cout<<array.front_index()<<" "<<array.rear_index()<<endl;

    array.show();

    cout<<array.front_index()<<" "<<array.rear_index()<<endl;
    array.dequeue();
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.dequeue();
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.dequeue();
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.dequeue();
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.dequeue();
    cout<<array.front_element()<<" "<<array.front_index()<<" "<<array.rear_element()<<" "<<array.rear_index()<<endl;
    array.dequeue();    
    cout<<array.front_index()<<" "<<array.rear_index()<<endl;

    array.show();

    return 0;
}
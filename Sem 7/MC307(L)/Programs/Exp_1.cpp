// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
class Time{
    int hour, minute, seconds;
    public:
        Time(): hour(0),minute(0),seconds(0){}
        void setTime(int hr, int min, int sec){
            hour = hr;
            minute = min;
            seconds = sec;
        }
        void print() const{
            if(hour<0 || hour>24 || minute<0 || minute>60 || seconds<0 || seconds>60)
                std::cout<<"Invalid Input"<<std::endl;
            else
                std::cout<<hour<<":"<<minute<<":"<<seconds<<std::endl;
        }
};

int main(){
    Time t1, t2;
    t1.setTime(12,30,45);
    t2.setTime(5,15,5);

    std::cout<<std::endl;
    std::cout<<"Time of object t1: ";
    t1.print();
    std::cout<<"Time of object t2: ";
    t2.print();
    std::cout<<std::endl;
    return 0;
}

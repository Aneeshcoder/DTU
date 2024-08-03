// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
class Time{
    int hour, minute, seconds;
    public:
        Time(): hour(0),minute(0),seconds(0){
            std::cout<<"Default constructor called !!!"<<std::endl;
        }
        Time(int h, int m, int s): hour(h),minute(m),seconds(s){
            std::cout<<"Parameterized constructor called !!!"<<std::endl;
        }
        ~Time(){
            std::cout<<"Destructor called for Time: ";
            print();
            std::cout<<std::endl;
        }
        void print() const{
            if(hour<0 || hour>24 || minute<0 || minute>60 || seconds<0 || seconds>60)
                std::cout<<"Invalid Input"<<std::endl;
            else
                std::cout<<hour<<":"<<minute<<":"<<seconds<<std::endl;
        }
};

int main(){
    std::cout<<std::endl;
    Time t1;
    t1.print();

    std::cout<<std::endl;
    Time t2(12, 15, 30);    
    t2.print();
    std::cout<<std::endl;
    return 0;
}

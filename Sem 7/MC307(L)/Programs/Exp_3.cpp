// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
class operatorOverloading{
    int value;
    public:
        operatorOverloading(int v=0): value(v){}
        
        operatorOverloading operator +(const operatorOverloading &c){
            return operatorOverloading(value + c.value);
        }
        operatorOverloading operator -(const operatorOverloading &c) {
            return operatorOverloading(value - c.value);
        }
        operatorOverloading &operator ++(){
            value++;
            return *this;
        }
        operatorOverloading operator ++(int){
            operatorOverloading temp = *this;
            value++;
            return temp;
        }
        void display() const{
            std::cout<<value;
        }
};

int main() {
    operatorOverloading c1(5), c2(3), c3;
    std::cout<<std::endl;

    std::cout<<"Initial values: ";
    std::cout<<"c1 = ";
    c1.display();
    std::cout<<", c2 = ";
    c2.display();
    std::cout<<", c3 = ";
    c3.display();
    std::cout<<std::endl<<std::endl;

    // Binary + operator
    c3 = c1 + c2;
    std::cout<<"After addition: ";
    c3.display();
    std::cout<<std::endl<<std::endl;

    // Binary - operator
    c3 = c1 - c2;
    std::cout<<"After subtraction: ";
    c3.display();
    std::cout<<std::endl<<std::endl;

    // Prefix ++ operator
    ++c1;
    std::cout<<"After prefix increment on c1: ";
    c1.display();
    std::cout<<std::endl<<std::endl;

    // Postfix ++ operator
    c2++;
    std::cout<<"After postfix increment on c2: ";
    c2.display();
    std::cout<<std::endl<<std::endl;
    return 0;
}

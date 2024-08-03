// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
void divide(int num, int den){
    try{
        if(den == 0){
            throw std::runtime_error("Denominator is zero !");
        }
        double result = static_cast<double>(num)/den;
        std::cout<<"Result: "<<result<<std::endl<<std::endl;
    }
    catch(const std::runtime_error &err){
        std::cerr<<"Exception caught in divide(): "<<err.what()<<std::endl<<std::endl;
        throw;
    }
}

int main(){
    std::cout<<std::endl;
    try{
        divide(10, 2);
        divide(10, 0);
    }
    catch(const std::exception& err){
        std::cerr<<"Exception caught in main(): "<<err.what()<<std::endl<<std::endl;
    }
    std::cout<<std::endl;
    return 0;
}

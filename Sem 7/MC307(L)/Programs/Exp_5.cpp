// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
template<typename Template_example>
class Class_example{
    private:
        Template_example item;
    public:
        Class_example(Template_example i): item(i){}
        Template_example getItem() const{
            return item;
        }
        void setItem(Template_example i){
            item = i;
        }
        void display() const{
            std::cout<<"Item in the Specialized Class: "<<item<<std::endl;
        }
};

int main(){
    std::cout<<std::endl;
    Class_example<int> int_example(5);
    std::cout<<"Integer Example: ";
    int_example.display();
    std::cout<<std::endl;

    Class_example<double> double_example(3.14);
    std::cout<<"Double Example: ";
    double_example.display();
    std::cout<<std::endl;

    Class_example<std::string> string_example("Hello, Templates !");
    std::cout<<"String Example: ";
    string_example.display();
    std::cout<<std::endl;
    return 0;
}

// Aneesh Panchal
// 2K20/MC/21

#include<iostream>
#include<string>
class Person{
    protected:
        std::string first_name;
        std::string last_name;
    public:
        Person(const std::string &fname, const std::string &lname): 
            first_name(fname), last_name(lname){}
        void displayPerson() const{
            std::cout<<"Name: "<<first_name<<" "<<last_name<<std::endl;
        }
};

class Employee: public Person{
    protected:
        int employee_id;
    public:
        Employee(const std::string &fname, const std::string &lname, int id): 
            Person(fname, lname), employee_id(id){}
        void displayEmployee() const{
            displayPerson();
            std::cout<<"Employee ID: "<<employee_id<<std::endl;
        }
};

class Manager: public Employee{
    private:
        std::string employee_designation;
        double employee_salary;
    public:
        Manager(const std::string &fname, const std::string &lname, int id, const std::string &designation, double salary): 
            Employee(fname, lname, id), employee_designation(designation), employee_salary(salary){}
        void displayManager() const{
            displayEmployee();
            std::cout<<"Designation: "<<employee_designation<<std::endl;
            std::cout<<"Salary: $"<<employee_salary<<std::endl;
        }
        double getSalary() const{
            return employee_salary;
        }
};

int main(){
    std::cout<<std::endl;
    Manager m1("Dhruv", "Rana", 1001, "Tech Head", 75000);
    Manager m2("Aneesh", "Panchal", 1002, "Research Head", 85000);
    Manager m3("Anshul", "Aggarwal", 1003, "Corporate Head", 80000);

    m1.displayManager();
    std::cout<<std::endl;
    m2.displayManager();
    std::cout<<std::endl;
    m3.displayManager();
    std::cout<<std::endl;

    if(m1.getSalary()>m2.getSalary() && m1.getSalary()>m3.getSalary()){
        std::cout<<"Highest salary: $"<<m1.getSalary()<<std::endl;
        std::cout<<"Manager with highest salary have ";
        m1.displayPerson();
    } 
    else if(m2.getSalary()>m1.getSalary() && m2.getSalary()>m3.getSalary()){
        std::cout<<"Highest salary: $"<<m2.getSalary()<<std::endl;
        std::cout << "Manager with highest salary have ";
        m2.displayPerson();
    } 
    else{
        std::cout<<"Highest salary: $"<<m3.getSalary()<<std::endl;
        std::cout<<"Manager with highest salary have ";
        m3.displayPerson();
    }
    std::cout<<std::endl;
    return 0;
}

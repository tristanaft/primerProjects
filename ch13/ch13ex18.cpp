#include<iostream>
#include<string>
#include<vector>

//If we require "each employee object has a different ID" then yes we need copy control
//so the copied object has a different ID than the original object
//but that just makes me wonder, what would the point of copying an employee object be?
//

class Employee{
public:
    Employee(): myId(idStart++), name(std::string()) {}
    explicit Employee(const std::string& str): myId(idStart++), name(str) {}
    Employee(const Employee& orig): myId(idStart++), name(orig.name) {}
    Employee &operator=(const Employee &e){
        name = e.name;
        //id = ++eid;  // keep the old id
        return *this;
        };



    int getId() {return myId;}
    std::string getName() {return name;}
    void setName(const std::string s) {name = s;};
private:
    static int idStart;
    std::string name;
    int myId;
};

int Employee::idStart = 0;


int main(){
    Employee e1;
    e1.setName("Albertram");
    std::cout << e1.getName() << " " << e1.getId() << std::endl;
    Employee e2("Blavid");
    std::cout << e2.getName() << " " << e2.getId() << std::endl;
    Employee e3 = e2;
    std::cout << e3.getName() << " " << e3.getId() << std::endl;
    Employee e4(e1);
    std::cout << e4.getName() << " " << e4.getId() << std::endl;
    std::vector<Employee> staff;
    std::cout <<"This is where copy control gets weird..." <<std::endl;
    std::cout <<"Lets put A and B into a vector and then print what the vector gets sent..." <<std::endl;
    staff.push_back(e1);
    staff.push_back(e2);

    for(Employee x: staff){
        std::cout << x.getName() << " " << x.getId() << std::endl;
    }
    std::cout <<"These have different IDs because they are different objects..." <<std::endl;
    std::cout <<"This is because if we pass Employee objects, they will be copied" <<std::endl;

    std::cout <<"We can get around this by making the vector contain Employee*" <<std::endl;
    std::vector<Employee *> staff2;
    Employee *pe1,*pe2;
    pe1=&e1;
    pe2=&e2;
    staff2.push_back(pe1);
    staff2.push_back(pe2);

    for(auto x: staff2){
        std::cout << x -> getName() << " " << x->getId() << std::endl;
    }
    std::cout <<"This does involve pointers though, and so introduces potential for error..." <<std::endl;










    return 0;
}
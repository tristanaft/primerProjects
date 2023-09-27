#include <string>
#include <iostream>

struct Person
{
    std::string name;
    std::string address;

    std::string getName() const {return name;}
    std::string getAddress() const {return address;}

};

int main()
{
    Person p;
    p.name = "first last";
    p.address = "somewhere";

    //std::cout << p.name << std::cout; this line doesnt work.

    return 0;
}
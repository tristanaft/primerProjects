#include<string>
#include<iostream>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): 
    ps(new std::string(s)), i(0) { }

    //COPY CONSTRUCTOR
    HasPtr(HasPtr &orig): 
    ps(new std::string(*orig.ps)), i(orig.i) {
        std::cout << "Copy constructor used." <<std::endl;
     }

    //COPY-ASSIGNMENT OPERATOR
    HasPtr& operator=(const HasPtr& rhs){
        //note: this has issues when something is set EQUAL TO ITSELF
        delete ps; //delete old memory
        ps = new std::string(*rhs.ps);
        i = rhs.i;
        std::cout << "Copy-assignment operator used" <<std::endl;
        return *this;
    }

    //DESTRUCTION OPERATOR
    ~HasPtr(){
        delete ps;
    }

    void set(const std::string &s){
        *ps = s;
    }

    std::string &get(){
        return *ps;
    }

private:
    std::string *ps;
    int i;
};

int main(){

    std::string s = "This is a string";
    HasPtr hp1(s);
    HasPtr hp2;
    hp2 = hp1;
    HasPtr hp3(hp2);
    hp2.set("This is a different string");

    std::cout << hp1.get() <<std::endl;
    std::cout << hp2.get() <<std::endl;
    std::cout << hp3.get() <<std::endl;
    


    return 0;
}
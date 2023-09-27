#include<iostream>
#include<string>

class base{
public:
    std::string name() {return basename;}
    virtual void print(std::ostream& os) {os << basename;}
private:
    std::string basename;
};

class derived: base{
public:
    void print(std::ostream& os) {base::print(os); os << " " << i;}
    //needed to specify base::print, or else it is assuming the print function in derived...
    //which you are in the process of defining...
private:
    int i;
};


int main(){

    return 0;
}
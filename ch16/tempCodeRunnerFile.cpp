#include <iostream>
#include <string>

//this is cool, can print a bunch of stuff all at once...
//weird you use induction but base case defined outside of the function
//but whatever

template <typename T>
std::ostream & 
print(std::ostream& os, const T& t){
    os << t;
    return os;
}

template <typename T, typename... Args>
std::ostream & 
print(std::ostream& os, const T& t, const Args&... rest){
    os << t << " ";
    return print(os, rest...);
}


int main(){
    int i = 1, j=2;
    double d = 1.2;
    char c = 'x';
    std::string s = "blah";
    print(std::cout, i);
    std::cout << std::endl;
    print(std::cout, i, d, c);
    std::cout << std::endl;
    print(std::cout, i, d, c, s, j);
    std::cout << std::endl;


    return 0;
}
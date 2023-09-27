#include <iostream>
#include <string>

std::istream &read(std::istream& is){
    is.clear();

    std::string str;
    while(is>>str){
        std::cout << str << " ";
    }
    std::cout << std::endl;
    is.clear();

    return is;
}

int main(){

    std::cout << "Type something: ";

    read(std::cin);

    std::cout <<std::endl;

    return 0;
}
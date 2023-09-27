#include <iostream>
#include <string>

template <typename T, size_t N>
constexpr size_t arrSize(T (&arr)[N]) {
  return N;
}

int main(){

    int arrInt[] = {1,2,3,4,5,6,7};
    std::string arrStr[] = {"blah","blah","blah"};
    char arrChr[] = {'c','h','a','r'};
    std::cout << arrSize(arrInt) <<std::endl;
    std::cout << arrSize(arrStr) <<std::endl;
    std::cout << arrSize(arrChr) <<std::endl;

    return 0;
}
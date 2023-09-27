#include<iostream>

void reset(int & i){
    i = 0;
}

int main(){
    int a=1;

    std::cout << "a= " << a << std::endl;

    std::cout << "RESET!" << std::endl;

    reset(a);

    std::cout << "a= " << a << std::endl;


    return 0;
}
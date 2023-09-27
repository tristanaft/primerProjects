#include<iostream>

int main(){

    int i = 10;

    auto f1 = [&i](){
        return i>0 ? --i, false : true;
    };
    std::cout << i << " ";
    while(!f1()){
        std::cout << i << " ";
        f1();
        std::cout << i << " ";
    }
    //so, i is decremented twice each loop,
    //once when while is checked, and once inside the loop.

    std::cout << std::endl;



    return 0;
}
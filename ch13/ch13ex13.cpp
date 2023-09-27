#include<iostream>
#include<vector>

struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {std::cout << "X(const X&)" << std::endl;}
};

int main(){

    X x1;
    X x2(x1);
    std::vector<X> vx;
    vx.push_back(x1);
    vx.push_back(x2);



    return 0;
}
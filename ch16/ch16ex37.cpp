#include <iostream>

int main(){
    //sure, this works fine
    //but, you have to specify an explicit template argument
    int a = 1, c=3;
    double b = 2.3;
    auto m = std::max<double>(a, b);
    std::cout << m << std::endl;
    //I think that what is going on here is that passing the argument <double>
    //will convert the int a = 1 to double a = 1.0.
    //lets test that out in the reverse...

    auto m2 = std::max<int>(a, b);
    std::cout << m2 << std::endl;
    //like I thought, this converts b to int and does the max.




return 0;
}
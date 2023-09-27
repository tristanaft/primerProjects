#include <iostream>

int main()
{

    int i; double d;

    //d = i = 3.5; warning, implicit conversion from double to int
    //changes value from 3.5 to 3.
    i = d = 3.5; //this works fine though, but probably a bad idea still.
    
    
    std::cout << d << " " << i << std::endl;





    return 1;
}
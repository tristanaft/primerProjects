#include <iostream>

int main()
{
    int x=10, y=15;     //initialize some ints
    int *p1 = &x;       //pointer p1 points to x

    *p1 += 1;           //change value of pointer
    std::cout << *p1 << std::endl; //check I did this right
    
    p1 = &y;            //change which object it points to
    std::cout << *p1 << std::endl;   //check


    return 0;
}
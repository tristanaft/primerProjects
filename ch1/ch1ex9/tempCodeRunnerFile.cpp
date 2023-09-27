#include <iostream>

int main()
{
    int sum = 0;
    int val = 50;

    while(val<=100)
    {
        sum+=val;
        ++val;
    }

    std::cout << "The sum of all numbers between 50 and 100 is: " << sum 
    << std::endl;


    return 0;
}
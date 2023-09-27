#include <iostream>

int main()
{
    int x = 0;      //starting value
    int y = 0;      //ending value
    int sum = 0;    //sum btw two numbers

    std::cout << "Enter two numbers and this program will calculate"
    << " the sum of all values between them.\n" << std::endl;



    std::cout << "Enter the first number: ";
    std::cin >> x; 
    std::cout << "\n";
    std::cout << "Enter the second number: ";
    std::cin >> y;
    std::cout << "\n";

    //Now, need to figure out which of x and y is the bigger one
    int start = std::min(x,y);
    int end = std::max(x,y);

    while(start<=end)
    {
        sum+=start;
        ++start;
    } 

    std::cout << "The sum of all numbers between " << start
    << " and " << end << " is: " << sum 
    << std::endl;


    return 0;
}
#include <iostream>

int main()
{

    std::cout << "Enter numbers to be summed (end with a non int):" << std::endl;
    
    int sum = 0, value = 0;
    while (std::cin >> value)
    {
        sum+=value;
    }

    std::cout << "The sum is: " << sum << std::endl;







    return 0;
}
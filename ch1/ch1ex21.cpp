#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;

    std::cout << "Enter a two of sale items with the same ISBN in the format: \n"
    <<"ISBN #copies price\n";
    std::cout << "And this program will calculate their sum." << std::endl;

    std::cin >> item1 >> item2;

    if(item1.isbn()==item2.isbn())
    {
        std::cout << "The sum is: " << item1+item2 << std::endl;
        return 0; //return success
    }
    else
    {
        std::cout<<"Sales items must have the same ISBN.";
        return -1; //return failure
    }


}
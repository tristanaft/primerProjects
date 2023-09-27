#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item;

    std::cout << "Enter a set of sales items in the format: \n"
    <<"ISBN #copies price" << std::endl;
    while(std::cin >> item){
        std::cout << item;
    }

    return 0;
}
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;


    if(std::cin >> total) //if reading from total
    {
        Sales_item trans; //variable to hold current transaction
        int count = 0;
        while(std::cin >> trans)
        {
            if(total.isbn() == trans.isbn())
            {
                ++count;
            }
            else
            {
                std::cout << trans.isbn() << ": " << count << std::endl;
            }
        }



        return 0;
    }
    else //hit this if stream is empty
    {
        std::cout << "No data entered." << std::endl;
        return -1;
    }


}
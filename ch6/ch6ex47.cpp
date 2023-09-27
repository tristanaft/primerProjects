#include <iostream>
#include <vector>

using std::vector;


void vecPrintInt(const vector<int>::iterator beg,
              const vector<int>::iterator end)
{
    #ifndef NDEBUG //with the run button, this is automatically executed
    std::cout << "In function: " << __func__ << ", "
            << "Vector size: " << end - beg << std::endl;
    #endif




    if (beg==end)
        return;
    std::cout << *beg << " ";
    vecPrintInt(beg+1,end);

}

int main(){

    vector<int> v = {1,2,3,4,5,4,3,2,1};
    vecPrintInt(v.begin(),v.end());
    std::cout << std::endl;


    return 0;
}
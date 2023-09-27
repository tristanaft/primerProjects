#include <iostream>
#include <vector>

using std::vector;


void vecPrintInt(const vector<int>::iterator beg,
              const vector<int>::iterator end)
{
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
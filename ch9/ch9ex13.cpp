#include <vector>
#include <list>
#include <iostream>

int main(){

    std::list<int> li = {1,2,3,4,5};
    std::vector<int> vi = {2,4,6,8};

    std::vector<double> vd1(vi.begin(), vi.end());
    std::vector<double> vd2(li.begin(), li.end());

    std::cout << vd1[0] << " " << vd2[0] << std::endl; 
    





    return 0;
}
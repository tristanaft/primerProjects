#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

void printList(std::list<int> lst){
    for(int x: lst) std::cout << x << " ";
}

int main(){

    std::vector<int> vi ={1,2,3,4,5,6,7,8,9};
    std::list<int> liF, liB, liI;

    std::copy(vi.cbegin(),vi.cend(),std::front_inserter(liF));
    std::copy(vi.cbegin(),vi.cend(),std::back_inserter(liB));
    std::copy(vi.cbegin(),vi.cend(),std::inserter(liI,liI.begin()));

    printList(liF);
    std::cout << "\n";
    printList(liB);
    std::cout << "\n";
    printList(liI);
    std::cout << "\n";
    

    //auto fi = std::front_inserter(liF);
    //auto bi = std::back_inserter(liB);









    return 0;
}
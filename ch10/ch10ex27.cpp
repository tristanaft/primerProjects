#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

int main(){

    std::vector<int> vi;
    std::cout << "Enter some ints: ";
    int i;
    while(std::cin >> i)
        vi.push_back(i);

    std::list<int> li;
    std::cout << std::endl;

    std::sort(vi.begin(), vi.end());

    std::unique_copy(vi.begin(),vi.end(),std::back_inserter(li));

    //for(auto x : li) std::cout << x << " ";

    std::for_each(li.begin(),li.end(),
    [](int x){std::cout << x << " ";});

    std::cout << std::endl;

    return 0;
}
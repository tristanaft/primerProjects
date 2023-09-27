#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

void partA(){
    std::vector<int> vi = {1000, 2000, 3000, 4000};
    std::cout << "There are " << std::count_if(vi.begin(),vi.end(),
        std::bind(std::greater<int>(), std::placeholders::_1, 1024)) << " values greater than 1024. \n";
}

void partB(){
    std::vector<std::string> vs = {"pooh", "pooh", "not pooh 1", "pooh", "not pooh 2" , "pooh"};
    auto vsIter = find_if(vs.begin(), vs.end(),
    std::bind(std::not_equal_to<std::string>(), std::placeholders::_1, "pooh"));
    std::cout << *vsIter << std::endl;

}

void partC(){
    std::vector<int> vi = {1000, 2000, 3000, 4000};
    std::for_each(vi.begin(),vi.end(),
    std::bind(std::multiplies<int>(), std::placeholders::_1, 2));
}

int main(){
    partA();
    partB();
    partC();

    return 0;
}

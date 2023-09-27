#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

bool check_size(const std::string &s, std::string::size_type sz){
    return s.size() >= sz;
}

bool check_size2(const std::string &s, int sz){
    return sz!=0 && !check_size(s,sz);
}

using namespace std::placeholders;

int main(){

    std::vector<int> vec = {1,1};

    int maxSteps=10;
    auto i1 = vec.begin();
    auto i2 = vec.begin();
    ++i2;

    for(int step=0; step<maxSteps;step++){
        vec.push_back(vec[step] + vec[step+1]);
    } //fibonacci sequence

    for(auto x: vec){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::string str = "word";

    auto item = find_if(vec.begin(),vec.end(),
    std::bind(check_size2, str, _1));

    std::cout << *item <<std::endl;



    return 0;
}
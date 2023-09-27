#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

void partA(){
    std::vector<int> vec; std::list<int> lst; int i;
    while(std::cin>>i){
        lst.push_back(i);
    }
    //vector currently empty, need space
    vec.resize(lst.size());
    copy(lst.cbegin(), lst.cend(),vec.begin());
}

void partB(){
    std::vector<int> vec;
    //vec.reserve(10); //this does NOT reserve space for 10 elements
    vec.resize(10); //this is what you need to do...
    std::fill_n(vec.begin(),10,0);
}

int main(){
    return 0;
}
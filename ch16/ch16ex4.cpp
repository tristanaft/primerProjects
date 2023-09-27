#include<string>
#include<vector>
#include<list>
#include<iostream>

template<typename Iter, typename Val>
Iter my_find(Iter beg, Iter end, const Val& target){
    for(;beg != end; ++beg){
        if(*beg == target){
            return beg;
        }
    }
    return end;
}

int main(){

    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    auto test = my_find(vec.begin(), vec.end(), 7);
    std::cout << "Look for 7, got : " << *test << std::endl;

    std::list<std::string> ls{"Here","are","a","bunch","of","strings"};
    auto test2 = my_find(ls.begin(), ls.end(), "of");
    std::cout << "Look for 'of', got : " << *test2 << std::endl;





    return 0;
}
#include<vector>
#include<list>
#include<iostream>

bool hasValue(std::vector<int>::iterator begin,
                    std::vector<int>::iterator end, const int i){
    while(begin!=end){
        if(*begin == i){
            return true;
            }
        begin++;
    }
    if(begin==end){
        return false;
    }
}

std::vector<int>::iterator getIter(std::vector<int>::iterator begin,
                    std::vector<int>::iterator end, const int i){

    while(begin!=end){
        if(*begin == i){
            return begin;
            }
        begin++;
    }

    if(begin==end){
    return end;
    }
}



int main(){
    std::vector<int> vec = {1,2,3,4,5,6,7};
    auto beg = vec.begin();
    auto end = vec.end();
    bool val = hasValue(beg,end,4);
    auto loc = getIter(beg,end,4);

    std::cout << val << std::endl;
    std::cout << *loc << std::endl;



    return 0;
}
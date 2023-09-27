#include<iostream>
#include<string>


template <typename T, size_t N>
T* arr_begin(T (&arr)[N]){
    return arr;
}

template <typename T, size_t N>
T* arr_end(T (&arr)[N]){
    return arr+N;
}

int main(){
    int arri[] = {1,2,3,4,5};
    std::string arrstr[] = {"Yet", "more", "strings"};
    auto aiBeg = arr_begin(arri);
    auto aiEnd = arr_end(arri);
    auto asBeg = arr_begin(arrstr);
    auto asEnd = arr_end(arrstr);
    //oh yeah, last element is one BEFORE the end...
    std::cout   << *aiBeg << " "
                << *(aiEnd-1) << " "
                << *asBeg << " "
                << *(asEnd-1) << std::endl;


    return 0;
}
#include<string>
#include<iostream>

template<typename T> 
int compare(T& l, T& r){
    if(l < r) return 1;
    else if(r < l) return -1;
    else return 0; //if equal.
}


int main(){
    int a=1, b=2;
    std::cout << "compare(1, 2) = "<< compare(a,b) << std::endl;

    std::string c="blah2", d="blah1";
    std::cout << "compare(blah2, blah1) = "<< compare(c,d) << std::endl;

    double e=1.0, f=1.0;
    std::cout << "compare(1.0, 1.0) = "<< compare(e,f) << std::endl;



    return 0;
}
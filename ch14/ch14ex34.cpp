#include<iostream>
#include<string>

//I guess I will have it  return strings?
class ifelse{
public:
std::string operator()(int i, std::string s1 = "zero", std::string s2 = "nonzero"){
    if(i == 0)
        return s1;
    else   
        return s2;
}

};



int main(){

    ifelse ie;
    //I gave this default arguments, but you can have it return any strings you want
    //but you can't change the condition of i==0 obviously.

    std::cout << "Enter an int: ";
    int x;
    std::cin >> x;
    std::cout << "The input is " << ie(x) << std::endl;

    return 0;
}
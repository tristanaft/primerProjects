#include<string>
#include<iostream>
#include<vector>


bool isShortString(std::string s){
    return s.length() < 5;
}

void printVec(std::vector<std::string> vec){
    for(const auto &s:vec)
        std::cout << s << " ";
    std::cout << std::endl;
}


int main(){
    std::vector<std::string> vecStr;
    std::cout << "Enter some words here: ";
    std::string str;
    while(std::cin >> str){
        if(str == "(done)")
            break;
        vecStr.push_back(str);
    };
    printVec(vecStr);



    return 0;
}
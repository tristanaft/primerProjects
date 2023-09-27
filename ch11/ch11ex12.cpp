#include<vector>
#include<utility>
#include<string>
#include<iostream>

int main(){

    std::string str;
    int i;
    std::vector<std::pair<std::string,int>> vec;
    while(std::cin >> str >> i){
        //std::pair<std::string,int> p = {str,i};
        //vec.push_back(p)
        vec.push_back({str,i});
        //vec.push_back(std::make_pair(s, i));
        //vec.push_back(std::pair<std::string, int>(s, i));
    }

    for(auto p: vec){
        std::cout << p.first << " " << p.second << std::endl;
    }



    return 0;
}
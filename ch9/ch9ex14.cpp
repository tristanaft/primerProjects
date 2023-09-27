#include<list>
#include<vector>
#include<iostream>
#include<string>

int main(){

    std::list<char*> lc{"aaa","bbb","ccc"};
    std::vector<std::string> vs;
    vs.assign(lc.begin(),lc.end());
    for(auto str:vs)
        std::cout<< str << " ";
    std::cout<<std::endl;
    //something about this might not be allowed...
    //but it is just a weird quirky thing to do maybe?








    return 0;
}
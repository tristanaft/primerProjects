#include <map>
#include <iostream>



int main(){

    std::map<int,int> m;

    std::cout << "Enter some ints: \n";

    int a,b;
    while(std::cin >> a >> b){
        auto it =m.find(a); 
        if(it == m.end())
            m.insert({a,b});
        else it -> second = b;
    }

    for(auto & p : m){
        std::cout << p.first << " " << p.second << std::endl;
    }



    return 0;
}
#include <vector>
#include <iostream>

std::vector<int> *factory_int(){
    return new std::vector<int>;
}

void read(std::vector<int> *v, std::istream& is){

    for(int i; is >> i; v -> push_back(i)){ }
}


int main(){
    
    auto p1 = factory_int();

    read(p1,std::cin);

    for(auto x : *p1){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    delete p1;
    
    
    
    return 0;

}
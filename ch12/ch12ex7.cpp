#include <vector>
#include <memory>
#include <iostream>

typedef std::shared_ptr<std::vector<int>> shared_vec_ptr;

shared_vec_ptr factory_int(){
    return std::make_shared<std::vector<int>>();
}

void read(shared_vec_ptr v, std::istream& is){

    for(int i; is >> i; v -> push_back(i)){ }
}

void process(shared_vec_ptr v, const std::string name){

    std::cout << "Enter elements for " << name << ": " ;

    read(v,std::cin);
    std::cout << std::endl;

    for(auto x : *v){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


int main(){
    
    auto p1 = factory_int();
    auto p2 = factory_int();

    process(p1, "p1");

    
    
    
    return 0;

}
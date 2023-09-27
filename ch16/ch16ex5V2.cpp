#include<string>
#include<iostream>


template<typename Container>
void print(Container& c, std::ostream& os){
    for(auto& x: c){
        os << x << " ";
    }
    std::cout << std::endl;
}




int main(){

    int arri[] = {1,2,3,4,5};
    print(arri,std::cout);
    std::string arrstr[] = {"Yet", "more", "strings"};
    print(arrstr,std::cout);


    return 0;
}
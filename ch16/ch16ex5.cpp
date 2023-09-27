#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>



template<typename Container>
void print(Container c, std::ostream& os){
    for(auto x: c){
        os << x << " ";
    }
    std::cout << std::endl;
}



int main(){
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    std::list<std::string> ls{"Here","are","a","bunch","of","strings"};
    std::deque<std::string> dq = {"Here","are","some","more","strings"};

    std::cout << "Printing vector of ints:\n";
    print(vec, std::cout);

    std::cout << "Printing list of strings:\n";
    print(ls, std::cout);

    std::cout << "Printing deque of strings:\n";
    print(dq, std::cout);




    return 0;
}
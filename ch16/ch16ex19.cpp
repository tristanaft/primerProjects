#include<iostream>
#include<string>
#include<vector>
#include<deque>

//technically, this should take in an ostream& and output an ostream&
//but this is fine for the basic stuff I am doing here.
template<typename container>
void print(container& c){
    //have to use typename here, because the size type is 
    //dependent on the container.
    for(typename container::size_type idx = 0; idx != c.size(); ++idx){
        std::cout << c[idx] << " ";
    }
}



int main(){
    std::vector<int> vec = {1,2,3,4,5};
    print(vec);
    std::cout << std::endl;

    std::vector<std::string> vec2 = {"blah","foo","bar"};
    print(vec2);
    std::cout << std::endl;
    
    std::deque<int> dq = {2,4,6,8,10};
    print(dq);
    std::cout << std::endl;


    return 0;
}
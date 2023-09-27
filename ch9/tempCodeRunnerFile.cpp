#include<iostream>
#include<forward_list>

int main(){

    //int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    std::forward_list<int> fli = {0,1,1,2,3,5,8,13,21,55,89};

    auto prev = fli.before_begin();
    auto curr = fli.begin();
    auto end = fli.end();

    for(auto x:fli)
        std::cout<< x << " ";
    std::cout << std::endl;

    while(curr != fli.end()){
        if(*curr%2){
            curr = fli.erase_after(prev);}
        else{
            prev = curr;
            curr++;
        }
    }











    for(auto x:fli)
        std::cout<< x << " ";
    std::cout << std::endl;


    return 0;
}
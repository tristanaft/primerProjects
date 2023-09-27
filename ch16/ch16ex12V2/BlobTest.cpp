#include "Blob.h"
#include "BlobPtr.h"
#include <string>
#include <iostream>

int main(){

    Blob<std::string> sb = {"better", "string", "blob"};
    Blob<int> ib = {1,2,3,4};
    //even with just this, get the error,
    //the definition of std::initializer_list does not contain the expected constructor
    //which is just not true?

    //auto temp = sb.begin();
    //std::cout << *temp << std::endl;
    //so... I can dereference, but I cant do a range for yet?

    for(auto i: ib){
        std::cout << i << '\n';
    }

    for(auto s: sb){
        std::cout << s << '\n';
    }

    //well... range for works...
    //I am fairly sure everything else works... but I should write test code for everything...


    return 0;
}
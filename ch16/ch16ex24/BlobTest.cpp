#include "Blob.h"
#include "BlobPtr.h"
#include <string>
#include <iostream>

int main(){

    std::vector<std::string> vs = {"This", "is", "a", "sentence"};
    Blob<std::string> b(vs.begin(),vs.end());

    for(auto s : b){
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
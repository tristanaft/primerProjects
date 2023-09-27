#include "Blob.h"
#include <string>
#include <iostream>

int main(){

    Blob<std::string> sb = {"better", "string", "blob"};
    Blob<int> ib = {1,2,3,4};
    //even with just this, get the error,
    //the definition of std::initializer_list does not contain the expected constructor
    //which is just not true?

    //I put in begin() and end() so this should work now..
    for(auto s : sb){
        std::cout << s << std::endl;
    }
    for(auto i : ib){
        std::cout << i << std::endl;
    }

    Blob<std::string> sb2 = {"blah"};

    //if(sb == sb2){std::cout << "true\n";}
    //else{std::cout << "false\n";}
    //so, blobs of strings are apparently not good with == for some reason?
    //Undefined symbols for architecture x86_64:
    //"operator==(Blob<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > > const&, 
    //Blob<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >)", referenced from:

    //let's try int?
    Blob<int> ib2 = {2,3,4};
    if(ib == ib2){std::cout << "true\n";}
    else{std::cout << "false\n";}
    


    return 0;
}
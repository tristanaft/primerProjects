#include <iterator>
#include <list>
#include <string>
#include <fstream>
#include <iostream>

int main(){

    std::ifstream is("ch10ex42input.in");
    if(!is.is_open()){
        std::cout << "Error, cannot open file..." << std::endl;
        return -1;}
    
    std::istream_iterator<std::string> iter(is), eof;

    std::list<std::string> lst(iter,eof); //this is the easy way

    //this is the hard way...
    //while(iter!=eof) vs.push_back(*iter++);

    for(auto x : lst) std::cout << x << " ";
    std::cout << std::endl;

    lst.sort();
    lst.unique();

    for(auto x : lst) std::cout << x << " ";
    std::cout << std::endl;




    return 0;
}
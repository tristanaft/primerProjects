#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iostream>
#include <fstream>
#include "Sales_item.h"

//there are a lot more methods in Sales_item.h than I realized,
//I think I will make use of some of them
//I am also re-using the data from a previous exercise

bool sortIsbn(const Sales_item &lhs, const Sales_item &rhs){
    return lhs.isbn() < rhs.isbn();
}

void printSDVec(std::vector<Sales_item> sdv){
    for(Sales_item &sd: sdv){
    std::cout << sd;
    std::cout << std::endl;
    }
}

int main(){
    std::ifstream in("ch10ex12input.in");
    std::istream_iterator<Sales_item> i_iter(in),eof;
    std::vector<Sales_item> sdVec(i_iter,eof);
    
    //lets print the elements in sdVec:
    printSDVec(sdVec);
    //ok now we have the vector, lets sort it now.
    std::cout << std::endl; //give extra space

    std::stable_sort(sdVec.begin(),sdVec.end(),sortIsbn);

    printSDVec(sdVec);

    std::cout << std::endl;

    //std::vector<Sales_item> sdVec2;

    std::ostream_iterator<Sales_item> o_iter(std::cout, "\n");

    for(auto bg = sdVec.begin(); bg != sdVec.end();){

        auto stop = find_if(bg,sdVec.end(),
        [bg](Sales_item &si){return (*bg).isbn() != si.isbn();});
        //so, this is an iterator that goes to the end of the group
        //of duplicate ISBN entries, right?
        //now accumulate and send to ostream;
        o_iter = std::accumulate(bg,stop, Sales_item(bg->isbn()));

        bg = stop; //dont increase stop, it technically refers to
        //one past the isbn you are looking for, so putting it in the
        //beginning kinda increments it... idk how to explain.
    }

    std::cout << std::endl;

    



    return 0;
}
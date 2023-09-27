#include <iostream>
#include <fstream>
#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"

void runQueries(std::ifstream &infile){

    TextQuery tq(infile);
    while(true){
        std::cout << "Enter word to look for, or q to quit: ";
        std::string s;
        if(!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s));
    }

}

int main(){
    std::ifstream in("inputfile.in");
    //runQueries(in);
    TextQuery tq(in);
    Query q = Query("to");
    std::cout << q;





    

    return 0;
}
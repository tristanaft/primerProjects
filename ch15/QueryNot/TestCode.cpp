#include <iostream>
#include <fstream>

#include "Query.h"
#include "TextQuery.h"
#include <string>
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
    Query q = Query("is");
    std::cout <<"Rep: " << q.rep() << std::endl;
    QueryResult result = q.eval(tq);
    print(std::cout, result);

    Query qn = ~Query("to");
    std::cout <<"Rep: " << qn.rep() << std::endl;
    print(std::cout, qn.eval(tq));





    

    return 0;
}
#include <iostream>
#include <fstream>

#include "Query.h"
#include "TextQuery.h"
#include <string>
#include "QueryResult.h"
#include "AndQuery.h"


void runQueries(std::ifstream &infile){

    std::string bigLine(21, '=');
    TextQuery tq(infile);

    std::cout << "Test 1: basic TextQuery";
    Query q = Query("the");
    std::cout <<"Rep: " << q.rep() << std::endl;
    QueryResult result = q.eval(tq);
    print(std::cout, result);
    std::cout << bigLine << std::endl;

    std::cout << "Test 2: NotQuery" <<std::endl;
    Query qn = ~Query("I");
    std::cout <<"Rep: " << qn.rep() << std::endl;
    print(std::cout, qn.eval(tq));
    std::cout << bigLine << std::endl;

    std::cout << "Test 3: AndQuery" <<std::endl;
    Query qa = Query("to") & Query("be");
    std::cout <<"Rep: " << qa.rep() << std::endl;
    print(std::cout, qa.eval(tq));
    std::cout << bigLine << std::endl;

    std::cout << "Test 4: OrQuery" <<std::endl;
    Query qo = Query("in") | Query("that");
    std::cout <<"Rep: " << qo.rep() << std::endl;
    print(std::cout, qo.eval(tq));
    std::cout << bigLine << std::endl;

    std::cout << "Test 5: all operations together" <<std::endl;
    Query qc = Query("the") | ~Query("I") & Query("to") & Query("in") | Query("that");
    std::cout <<"Rep: " << qc.rep() << std::endl;
    print(std::cout, qc.eval(tq));
    std::cout << bigLine << std::endl;

    std::cout << "SUCCESS!" << std::endl;

}

int main(){
    std::ifstream in("inputfile.in");
    runQueries(in);
    
    return 0;
}
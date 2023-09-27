#include "QueryResult.h"

//have to direct initialize every element...
QueryResult::QueryResult(
    int tc, std::string qw, std::set<int> ln, std::vector<std::string> ql):
    totalCount(tc), queryWord(qw), lineNumbers(ln), queryLines(ql) { }

void QueryResult::print(){

    std::cout << queryWord <<" occurs " << totalCount << " times." << std::endl;

    int count = 0;
    for(auto x : lineNumbers){
        std::cout << "\t(line: " << x+1 << "): "<< queryLines[count] << std::endl;
        count++;
    }

}
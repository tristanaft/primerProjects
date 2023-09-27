#ifndef QUERYRESULT_H
#define QUERYRESULT_H


#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include <set>
#include <iostream>



class QueryResult{

public:
    void print();
    QueryResult() = default; //get this IF QUERY INVALID
    QueryResult(int, std::string, std::set<int>, std::vector<std::string>);
private:
    int totalCount;
    std::string queryWord;
    std::set<int> lineNumbers;
    std::vector<std::string> queryLines;

};

#endif
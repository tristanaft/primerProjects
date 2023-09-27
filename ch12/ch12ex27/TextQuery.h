#ifndef TEXTQUERY_H
#define TEXTQUERY_H

class QueryResult;
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include <set>
#include <algorithm>



class TextQuery{
    friend class QueryResult;
public:
    TextQuery(std::ifstream&); //initializer
    QueryResult query(const std::string); //output query result for given word
    void printText();
private:
    std::vector<std::string> entireText; //stored LINE BY LINE
    std::map<std::string, std::vector<int> > wordOccurrences;
    void addToMap(std::string,int);
};


#endif
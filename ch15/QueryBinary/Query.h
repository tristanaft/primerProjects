#ifndef QUERY_H
#define QUERY_H

class TextQuery;
class QueryResult;
class Query_base;

#include <memory>
#include <string>
#include <iostream>

class Query{
    //these operators need access to the shared_ptr constructor
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&);
    //interface functions: call the corresponding Query_base operations
    QueryResult eval(const TextQuery&) const;
    std::string rep() const;
private:
    Query(std::shared_ptr<Query_base> query): q(query) {}
    std::shared_ptr<Query_base> q;
};


#endif
#ifndef QUERY_H
#define QUERY_H

#include "QueryResult.h"
#include "TextQuery.h"
#include "Query_base.h"
#include "WordQuery.h"

class TextQuery;
class QueryResult;
class Query_base;

class Query{
    //these operators need access to the shared_ptr constructor
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    inline Query(const std::string& s): q(new WordQuery(s)){}
    //interface functions: call the corresponding Query_base operations
    QueryResult eval(const TextQuery& t) const {return q->eval(t);}
    std::string rep() const {return q->rep();}
private:
    Query(std::shared_ptr<Query_base> query): q(query) {}
    std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream& os, const Query& query){
        return os << query.rep();
}


#endif
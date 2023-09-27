#ifndef NOTQUERY_H
#define NOTQUERY_H

class TextQuery;
class QueryResult;

#include "Query_base.h"

class NotQuery: public Query_base{
    friend Query operator~(const Query&);
    NotQuery(const Query& q): query(q) {}
    std::string rep() const override {return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery& t) const override;
    Query query;
};


#endif
#ifndef QUERYBASE_H
#define QUERYBASE_H

class QueryResult;
#include "TextQuery.h"
#include<string>

class Query_base{
friend class Query;
protected:
    using line_no = TextQuery::line_no; //used in eval functions
    virtual ~Query_base() = default;
private:
    //eval returns the QueryResult that matches this Query
    virtual QueryResult eval(const TextQuery&) const = 0;
    //rep is a string representation of this query
    virtual std::string rep() const = 0;
};


#endif
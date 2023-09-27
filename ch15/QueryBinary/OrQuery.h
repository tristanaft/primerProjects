#ifndef ORQUERY_H
#define ORQUERY_H

class TextQuery;
class QueryResult;
#include "BinaryQuery.h"

class OrQuery: public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& left, const Query& right):
        BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery&) const override;
};


#endif
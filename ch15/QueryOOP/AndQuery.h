#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "BinaryQuery.h"
#include <string>

class AndQuery: public BinaryQuery{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right):
        BinaryQuery(left, right, "&") {}
    QueryResult eval(const TextQuery&) const override;
};

#endif
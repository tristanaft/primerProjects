#include "NotQuery.h"

inline Query operator~(const Query& operand){
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

QueryResult
NotQuery::eval(const TextQuery& text) const {
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<std::set<std::vector<std::string>::size_type>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for(size_t n = 0; n != sz; ++n){
        if(beg == end){
            ret_lines->insert(n);
        }else if(beg != end){
            ++beg;
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}
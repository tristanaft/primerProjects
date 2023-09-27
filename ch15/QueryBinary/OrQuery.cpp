#include "OrQuery.h"
#include <memory>  // make_shared
#include "TextQuery.h"
#include "QueryResult.h"

QueryResult OrQuery::eval(const TextQuery& text) const {
    //virtual calls through the Query members lhs, rhs
    //calls to eval return QueryResult for each operand.
    auto right = rhs.eval(text), left = lhs.eval(text);
    //copy line #s from lhs
    auto ret_lines = 
        std::make_shared<std::set<TextQuery::line_no>>(left.begin(), left.end());
        //getting red squiggles again... not sure if it is VScode acting up...
        //VScode doesn't know what type left.begin and left.end are...
    ret_lines->insert(right.begin(), right.end());
    //insert lines from RHS
    return QueryResult(rep(), ret_lines, left.get_file());
};

//these inline specifications are messing up the code... I am going to take them off
Query operator|(const Query& lhs, const Query& rhs){
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}


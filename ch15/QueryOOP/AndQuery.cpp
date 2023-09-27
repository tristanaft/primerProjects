#include "AndQuery.h"
#include <memory>  // make_shared
#include <algorithm>  // set_intersection
#include <iterator>  // inserter
#include "TextQuery.h"
#include "QueryResult.h"

inline Query operator&(const Query& lhs, const Query& rhs){
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult
AndQuery::eval(const TextQuery& text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    //set to hold intersection of left and right
    //VSCODE IS BEING SUPER ANNOYING ABOUT THE TYPING OF RET_LINES
    //EVEN IF I WRITE IT ALL OUT!!!
    //it seems to not understand that std::vector<std::string>::size_type IS VALID
    auto ret_lines = std::make_shared<std::set<TextQuery::line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(),
        std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}


#include "NotQuery.h"
#include <memory>  // make_shared
#include "TextQuery.h"
#include "QueryResult.h"

QueryResult NotQuery::eval(const TextQuery &t) const {

  auto result = q.eval(t);
  auto ret_lines = std::make_shared<std::set<line_no>>();
  auto bg = result.begin(), ed = result.end();
  auto sz = result.get_file()->size();
  for (std::size_t n = 0; n != sz; ++n) {
    if (bg == ed || *bg != n)
      ret_lines->insert(n);
    else if (bg != ed)
      ++bg;
  }
  return QueryResult(rep(), ret_lines, result.get_file());
}

Query operator~(const Query &query) {
  // NOTE we cannot use `std::make_shared` here, because the type of the
  // dynamically created object and the type of the object pointed by shared
  // pointer are different.
  return std::shared_ptr<Query_base>(new NotQuery(query));
}
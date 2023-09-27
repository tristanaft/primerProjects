#include<string>
#include<iostream>


class Query_base{
friend class Query;
protected:
    //using line_no = TextQuery::line_no; //used in eval functions
    virtual ~Query_base() = default;
private:
    //eval returns the QueryResult that matches this Query
    virtual QueryResult eval(const TextQuery&) const = 0;
    //rep is a string representation of this query
    virtual std::string rep() const = 0;
};

class Query{
    //these operators need access to the shared_ptr constructor
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&); //builds a new WordQuery
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

class WordQuery: public Query_base{
friend class Query; //Query uses the WordQuery constructor
    WordQuery(const std::string& s): query_word(s) {}
    //concrete class: WordQuery defines all inherited pure virtual functions
    QueryResult eval(const TextQuery& t) const {return t.query(query_word);}
    std::string rep() const {return query_word;}
    std::string query_word; 
};

//can now define Query constructor:
inline
Query::Query(const std::string& s): q(new WordQuery(s)){}

class NotQuery: public Query_base{
    friend Query operator~(const Query&);
    NotQuery(const Query& q): query(q) {}
    std::string rep() const {return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery& t) const;
    Query query;
};
inline Query operator~(const Query& operand){
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}
class BinaryQuery: public Query_base{
protected:
    BinaryQuery(const Query& l, const Query& r, std::string s):
        lhs(l), rhs(r), opSym(s) {}
    //abstract class: BinaryQuery doesn't define eval
    std::string rep() const {return "(" + lhs.rep() + " " 
                                        + opSym + " " 
                                        + rhs.rep() + ")";}
    Query lhs, rhs;
    std::string opSym;
};



class TextQuery;
class QueryResult;




class OrQuery;
class AndQuery;

#ifndef Query_h
#define Query_h

#include "TextQuery.hpp" 

//-----------------------------------------------------------------------------
//          Class Query_base  
//          @functioning: A pure abstrct class for interface class Query
//-----------------------------------------------------------------------------

class Query_base {
    friend class Query;
protected:
    using Line_No = TextQuery::Line_No;
    // for voirtual function  
    virtual ~Query_base() = default;;
private:
    // pure abstrct vitual function for evaluating finding and reprensting string
    //  to print.
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual string rep() const = 0;
};



//-----------------------------------------------------------------------------
//          Class WordQuery  
//          
//          @functioning: which find word in TextQuery obj
//-----------------------------------------------------------------------------

class WordQuery : public Query_base {
    friend class Query;

    WordQuery(const string &s) : query_word(s) {}
    QueryResult eval(const TextQuery &t) const override {
        return t.queryWord(query_word); 
    }

    string rep() const override {return query_word;}
    string query_word;
};


//-----------------------------------------------------------------------------
//          Class Query  
//          @functioning: class for user interface which hide the class 
//              drerived structure. 
//-----------------------------------------------------------------------------

class Query : public Query_base {
friend Query operator ~(const Query &);
friend Query operator |(const Query &, const Query &);
friend Query operator &(const Query &, const Query &);

public: 
    // constructor to initializing string to find into Query obj
    Query(const string &);
    // diffrent type of objects using  eval() and rep() dynamicly.
    QueryResult eval(const TextQuery &t) const {
        return q->eval(t); 
    }
    string rep() const {
        return q->rep(); 
    }
private:
    // constructor for friend operators to construct Query obj,
    //  which meant to evalueating finnal result. 
    // 
    
    Query(shared_ptr<Query_base> query): q(query) {}
    shared_ptr<Query_base> q;
};

inline Query::Query(const string &s) : q(new WordQuery(s)) {}


ostream &
operator <<(ostream &os, const Query &query) {
    return os << query.rep();
}
//-----------------------------------------------------------------------------
//          Class NotQuery  
//          @functioning: class for not operating   
//-----------------------------------------------------------------------------

class NotQuery : public Query_base {
    friend Query operator ~(const Query &);
    NotQuery(const Query &q) : query(q) {}
    
    string rep() const override {return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery &) const override;
    
    Query query;
}; 

inline Query operator ~(const Query &operand) {
    return shared_ptr<Query_base> (new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<set<Line_No> > ();
    auto beg = result.begin(), end = result.end();

    // to find line_no from file which don't include the word
    auto sz = result.getFile()->size(); 
    for (size_t i = 0; i != sz; ++i) {
        // store the line_no for thoese don't include the  word  in the text
        if (beg == end || *beg != i) 
            ret_lines->insert(i);
        // skip the line_no of the word that is in the file.
        else if (beg != end)
            ++beg;
    }

    return QueryResult(rep(), ret_lines, result.getFile());
}

//-----------------------------------------------------------------------------
//          Class BinaryQuery  
//          @functoining: Pure Abstract class for class AndQuery and OrQuery, 
//              which sotre their common information
//          
//-----------------------------------------------------------------------------

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, string s)
        : lhs(l), rhs(r), opSym(s) { }

    string rep() const override {
        return "(" + lhs.rep() + " "  
                   + opSym + " "
                   + rhs.rep() + ")";
    }

    Query lhs, rhs;
    string opSym;
};



//-----------------------------------------------------------------------------
//          Class AndQuery  
//          @functioning: class for operation &, which genertate Query obj 
//              which contian needed functions and information for operation 
//              &. 
//-----------------------------------------------------------------------------

class AndQuery : public BinaryQuery {
    friend Query operator &(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right) 
        : BinaryQuery(left, right, "&") { }
    
    QueryResult eval(const TextQuery &) const override;
};
 
inline Query operator &(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult 
AndQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);    
    // for void output, which mean there is no intersection between these two set
    auto ret_lines = std::make_shared<set<Line_No> >();
    
    set_intersection(left.begin(), left.end(), 
                    right.begin(), right.end(), 
                    inserter(*ret_lines, ret_lines->begin()));
    
    return QueryResult(rep(), ret_lines, left.getFile());
}


//-----------------------------------------------------------------------------
//          Class OrQuery  
//          @functioning: class for operation |, which contain need information
//              and function for the doing the | oeration.
//-----------------------------------------------------------------------------

class OrQuery : public BinaryQuery {
    friend Query operator |(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right) 
        : BinaryQuery(left, right, "&") { }
    
    QueryResult eval(const TextQuery &) const override;
};
 
inline Query operator |(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult 
OrQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);    
    // concatenate two sets 
    auto ret_lines = std::make_shared<set<Line_No> >(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());   

    return QueryResult(rep(), ret_lines, left.getFile());
}



#endif

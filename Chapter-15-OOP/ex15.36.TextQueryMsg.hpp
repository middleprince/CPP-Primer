#ifndef ex15_36_TextQueryMsg_h
#define ex15_36_TextQueryMsg_h

#include "TextQuery.hpp" 

//-----------------------------------------------------------------------------
//          Class Query_base  
//          A pure abstrct class for interface class Query
//-----------------------------------------------------------------------------

class Query_base {
    friend class Query;
protected:
    using Line_No = TextQuery::Line_No;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual string rep() const = 0;
};



//-----------------------------------------------------------------------------
//          Class WordQuery  
//          class word finding 
//-----------------------------------------------------------------------------

class WordQuery : public Query_base {
    friend class Query;

    WordQuery(const string &s) : query_word(s) {
        cout << "# Constructor from WordQuery #" << endl; 
    }
    QueryResult eval(const TextQuery &t) const override {
        return t.queryWord(query_word); 
    }

    string rep() const override {
        cout << "# rep() from WordQuery #" << endl;
        return query_word;}
    string query_word;
};


//-----------------------------------------------------------------------------
//          Class Query  
//          class for user interface 
//-----------------------------------------------------------------------------

class Query : public Query_base {
friend Query operator ~(const Query &);
friend Query operator |(const Query &, const Query &);
friend Query operator &(const Query &, const Query &);

public: 
    Query(const string &);
    QueryResult eval(const TextQuery &t) const {
        return q->eval(t); 
    }
    string rep() const {
        cout << "# rep() from Query #" << endl;
        return q->rep(); 
    }
private:
    Query(shared_ptr<Query_base> query): q(query) {
        cout << "# Constructor from Query private #" << endl; 
    }
    shared_ptr<Query_base> q;
};

inline Query::Query(const string &s) : q(new WordQuery(s)) {
    cout << "# Constructor from Query #" << endl; 
}


ostream &
operator <<(ostream &os, const Query &query) {
    return os << query.rep();
}
//-----------------------------------------------------------------------------
//          Class NotQuery  
//          class not operator manipulation 
//-----------------------------------------------------------------------------

class NotQuery : public Query_base {
    friend Query operator ~(const Query &);
    NotQuery(const Query &q) : query(q) {
        cout << "# Constructor from NotQuery #" << endl; 
    }
    
    string rep() const override {
        cout << "# rep() from NotQuery #" << endl;
        return "~(" + query.rep() + ")";}
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

    auto sz = result.getFile()->size(); 
    for (size_t i = 0; i != sz; ++i) {
        // There is no word found in text
        if (beg == end || *beg != i) 
            ret_lines->insert(i);
        // Found the word , then skip it's line number
        else if (beg != end)
            ++beg;
    }

    return QueryResult(rep(), ret_lines, result.getFile());
}

//-----------------------------------------------------------------------------
//          Class BinaryQuery  
//          Pure Abstract class for class AndQuery and OrQuery 
//-----------------------------------------------------------------------------

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, string s)
        : lhs(l), rhs(r), opSym(s) {
            cout << "# Constructor from BinaryQuery #" << endl; 
        }

    string rep() const override {
        cout << "# rep() from BinaryQuery #" << endl;
        return "(" + lhs.rep() + " "  
                   + opSym + " "
                   + rhs.rep() + ")";
    }

    Query lhs, rhs;
    string opSym;
};



//-----------------------------------------------------------------------------
//          Class AndQuery  
//          class for operation &
//-----------------------------------------------------------------------------

class AndQuery : public BinaryQuery {
    friend Query operator &(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right) 
        : BinaryQuery(left, right, "&") { 
            cout << "# Constructor from AndQuery #" << endl; 
        }
    
    QueryResult eval(const TextQuery &) const override;
};
 
inline Query operator &(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult 
AndQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);    
    auto ret_lines = std::make_shared<set<Line_No> >();
    
    set_intersection(left.begin(), left.end(), 
                    right.begin(), right.end(), 
                    inserter(*ret_lines, ret_lines->begin()));
    
    return QueryResult(rep(), ret_lines, left.getFile());
}


//-----------------------------------------------------------------------------
//          Class OrQuery  
//          class for operation |
//-----------------------------------------------------------------------------

class OrQuery : public BinaryQuery {
    friend Query operator |(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right) 
        : BinaryQuery(left, right, "&") {
            cout << "# Constructor from OrQuery #" << endl; 
        }
    
    QueryResult eval(const TextQuery &) const override;
};
 
inline Query operator |(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult 
OrQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);    
    auto ret_lines = std::make_shared<set<Line_No> >(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());   

    return QueryResult(rep(), ret_lines, left.getFile());
}




#endif

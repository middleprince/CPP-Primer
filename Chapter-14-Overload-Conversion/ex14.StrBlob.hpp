// Add operator []
// add pre++ pos++ pre-- pos--
// add operator + for StrBlobPtr pointer
// add const StrBlobPtr
// add * oprator and -> operator for StrBlobPtr and ConstStrBlobPtr

#ifndef CP5_ex14_StrBlob_h
#define CP5_ex14_StrBlob_h

#include <iostream>
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

#include <memory>
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

#include <exception>

class StrBlobPtr;
class ConstStrBlobPtr;

//---------------------------------------------------------
//          Class StrBlob 
//    StrBlob is to stimulate vector<string>
//---------------------------------------------------------

class StrBlob {
    typedef vector<string>::size_type size_type;
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend bool operator>(const StrBlob&, const StrBlob&);
    friend bool operator<=(const StrBlob&, const StrBlob&);
    friend bool operator>=(const StrBlob&, const StrBlob&);
 public:
    
    StrBlob() : data(make_shared<vector<string> >()){}
    StrBlob(initializer_list<string> il) 
        : data(make_shared<vector<string> >(il)) {}

    StrBlob(const StrBlob &old) : data(make_shared<vector<string> >(*old.data)) {}
    StrBlob& operator=(const StrBlob&);
    
    StrBlob(StrBlob &&rhs) noexcept : data(std::move(rhs.data)) {
        rhs.data = nullptr; 
    }
    StrBlob& operator=(StrBlob&&) noexcept;

        
    StrBlobPtr begin();
    StrBlobPtr end(); 

    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const; 

    string& operator[](std::size_t); 
    const string& operator[](std::size_t) const; 
    
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    
    void push_back(const string &s) {data->push_back(s);}
    void push_back(string &&s) {data->push_back(std::move(s));}
    
    void pop_back();
    const string &front() const;
    const string &back() const;

private:
    shared_ptr<vector<string> > data;
    void check(size_type i, const string &msg) const;
};

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);

inline void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

inline void StrBlob::pop_back() {
    check(0, "pop back on empty StrBlob");
    data->pop_back();
}

inline const string & StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

inline const string & StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

// overload operator [] for StrBlob
inline string& StrBlob::operator[](size_t n) {
    check(n, "location past begin"); 
    return (*data)[n];
} 

// overload operator [] for const StrBlob
inline const string& StrBlob::operator[](size_t n) const {
    check(n, "location past begin"); 
    return (*data)[n];
}


//-------------------------------------------------------------------
//          calss StrBlobPtr
//
// ------------------------------------------------------------------
class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
    
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    
    size_t locatoin() const {return curr;}
    
    string & operator*() const;
    string * operator->() const;

    StrBlobPtr& operator++();
    StrBlobPtr operator++(int);
    StrBlobPtr& operator--();
    StrBlobPtr operator--(int);
    
    StrBlobPtr& operator+=(size_t);
    StrBlobPtr& operator-=(size_t);
    StrBlobPtr operator+(size_t) const;
    StrBlobPtr operator-(size_t) const ;

    string& operator[](std::size_t );
    const string& operator[](std::size_t ) const;

private:
    weak_ptr<vector<string> > wptr;
    size_t curr;
    shared_ptr<vector<string> > check(size_t, const string&) const;
};

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

inline shared_ptr<vector<string> > 
StrBlobPtr::check(size_t i, const string& msg) const{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i > ret->size())
        throw std::out_of_range(msg);
    return ret;
}

//overload operator * for StrBlob
inline string & StrBlobPtr::operator *() const{
    auto p = check(curr, "derefrence past end"); 
    return (*p)[curr];

}

//overload operator -> for StrBlob
inline string * StrBlobPtr::operator ->() const{
    return & this->operator*();
}

// overload operator [] for  StrBlobPtr
inline string& StrBlobPtr::operator[](size_t n) {
    auto p = check(n, "location past begin"); 
    return (*p)[n];
}

// overload operator [] for const  StrBlobPtr
inline const string& StrBlobPtr::operator[](size_t n) const {
    auto p = check(n, "derefrence past end"); 
    return (*p)[n];
}

// posfix-increment opreator for StrBolbPtr
inline StrBlobPtr& StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


// prefix-increment opreator for StrBolbPtr
inline StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

// prefix-decrement for StrBlobPtr
inline StrBlobPtr& StrBlobPtr::operator--() {
    --curr;
    check(curr, "decrment past begin of StrBlobPtr");
    return *this;
}

// posfix-decrement for StrBlobPtr
inline StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

// operator += for StrBlobPtr
inline StrBlobPtr& StrBlobPtr::operator+=(size_t n) {
    curr += n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

// operator -= for StrBlobPtr
inline StrBlobPtr& StrBlobPtr::operator-=(size_t n) {
    curr -= n;
    check(curr, "decrement past end of StrBlobPtr");
    return *this;
}

// operator + for StrBlobPtr
inline StrBlobPtr StrBlobPtr::operator+(size_t n) const {
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;

}

// operator - for StrBlobPtr
inline StrBlobPtr StrBlobPtr::operator-(size_t n) const {
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;
}

//---------------------------------------------------
//  class ConstStrBlobPtr : the const verion Ptr
//---------------------------------------------------
class ConstStrBlobPtr {
    friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator<=(const ConstStrBlobPtr&, const StrBlobPtr&);
    
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    size_t locatoin() const {return curr;}
    
    ConstStrBlobPtr& operator++();
    ConstStrBlobPtr operator++(int);
    ConstStrBlobPtr& operator--();
    ConstStrBlobPtr operator--(int);
    
    ConstStrBlobPtr& operator+=(size_t);
    ConstStrBlobPtr& operator-=(size_t);
    ConstStrBlobPtr operator+(size_t) const;
    ConstStrBlobPtr operator-(size_t) const;

    const string & operator[](std::size_t ) const;
    const string & operator*() const;
    const string * operator->() const;

private:
    weak_ptr<vector<string> > wptr;
    size_t curr;
    shared_ptr<vector<string> > check(size_t, const string&) const;
};

bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);


inline shared_ptr<vector<string> > 
ConstStrBlobPtr::check(size_t i, const string& msg) const{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound ConstStrBlobPtr");
    if (i > ret->size())
        throw std::out_of_range(msg);
    return ret;
}

// overload operator * for ConstStrBlobPtr
inline const string & ConstStrBlobPtr::operator *() const{
    auto p = check(curr, "derefrence past end"); 
    return (*p)[curr];

}

// overload operator -> for ConstStrBlobPtr
inline const string * ConstStrBlobPtr::operator ->() const{
    return & this->operator*();
}

// overload operator [] for const  ConstStrBlobPtr
inline const string& ConstStrBlobPtr::operator[](size_t n) const {
    auto p = check(n, "derefrence past end"); 
    return (*p)[n];
}

// posfix-increment opreator for StrBolbPtr
inline ConstStrBlobPtr& ConstStrBlobPtr::operator++() {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}


// prefix-increment opreator for StrBolbPtr
inline ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
    ConstStrBlobPtr ret = *this;
    ++*this;
    return ret;
}

// prefix-decrement for ConstStrBlobPtr
inline ConstStrBlobPtr& ConstStrBlobPtr::operator--() {
    --curr;
    check(curr, "decrment past begin of ConstStrBlobPtr");
    return *this;
}

// posfix-decrement for ConstStrBlobPtr
inline ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
    ConstStrBlobPtr ret = *this;
    --*this;
    return ret;
}

// operator += for ConstStrBlobPtr
inline ConstStrBlobPtr& ConstStrBlobPtr::operator+=(size_t n) {
    curr += n;
    check(curr, "increment past end of ConstStrBlobPtr");
    return *this;
}

// operator -= for ConstStrBlobPtr
inline ConstStrBlobPtr& ConstStrBlobPtr::operator-=(size_t n) {
    curr -= n;
    check(curr, "decrement past end of ConstStrBlobPtr");
    return *this;
}

// operator + for ConstStrBlobPtr
inline ConstStrBlobPtr ConstStrBlobPtr::operator+(size_t n) const{
    ConstStrBlobPtr ret = *this;
    ret += n;    
    return ret;

}

// operator - for ConstStrBlobPtr
inline ConstStrBlobPtr ConstStrBlobPtr::operator-(size_t n) const{
    ConstStrBlobPtr ret = *this; 
    ret -= n;
    return ret;
}
#endif 

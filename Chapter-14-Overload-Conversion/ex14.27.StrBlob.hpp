// Add operator []
#ifndef ex14_27_StrBlob_h
#define ex14_27_StrBlob_h

#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlobPtr;
class StrBlob {
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend bool operator>(const StrBlob&, const StrBlob&);
    friend bool operator<=(const StrBlob&, const StrBlob&);
    friend bool operator>=(const StrBlob&, const StrBlob&);
 public:
    typedef vector<string>::size_type size_type;
    
    friend class StrBlobPtr;
    StrBlobPtr begin();
    StrBlobPtr end(); 
    
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    void push_back(const string &s) {data->push_back(s);}
    void pop_back();
    string &front() const;
    string &back() const;

    string& operator[](std::size_t); 
    const string& operator[](std::size_t) const; 

private:
    shared_ptr<vector<string> > data;
    void check(size_type i, const string &msg) const;
};

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string & operator*() const;
    size_t locatoin() const {return curr;}
    
    StrBlobPtr& operator++();
    StrBlobPtr operator++(int);
    StrBlobPtr& operator--();
    StrBlobPtr operator--(int);
    
    StrBlobPtr& operator+(size_t index) {
        check(curr+index, "increment " + to_string(index) + "past StrBolbPtr");
        curr += index;
        return *this;
    }

    string& operator[](std::size_t );
    const string& operator[](std::size_t ) const;

private:
    weak_ptr<vector<string> > wptr;
    size_t curr;
    shared_ptr<vector<string> > check(size_t, const string&) const;
};


StrBlob::StrBlob() : data(make_shared<vector<string> >()){}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string> >(il)){}

void StrBlob::check(size_type i, const string &msg) const{
    if (i >= data->size())
        throw out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop back on empty StrBlob");
    data->pop_back();
}

string & StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

string & StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}


StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}


shared_ptr<vector<string> > StrBlobPtr::check(size_t i, const string& msg) const{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i > ret->size())
        throw out_of_range(msg);
    return ret;
}

string & StrBlobPtr::operator *() const{
    auto p = check(curr, "derefrence past end"); 
    return (*p)[curr];

}

// overload == for StrBlob
bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return (*lhs.data == *rhs.data);
}

// overload != for StrBlob
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}


// overload == for StrBlobPtr
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return (lhs.curr == rhs.curr);
}
// overload != for StrBlobPtr
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

// overload < for StrBlob
bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
                                        rhs.data->begin(), rhs.data->end());

}

// overload > for StrBlob
bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
    return rhs < lhs;
}

// overload <= for StrBlob
bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs > rhs);
}
// overload >= for StrBlob
bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs > rhs);
}

// overload < for StrBlobPtr
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr < rhs.curr;
}

// overload > for StrBlobPtr
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr > rhs.curr;
}

// overload <= for StrBlobPtr
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs > rhs);
}

// overload >= for StrBlobPtr
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs < rhs);
}

// overload operator [] for StrBlob
string& StrBlob::operator[](size_t n) {
    check(n, "location past begin"); 
    return (*data)[n];
} 

// overload operator [] for const StrBlob
const string& StrBlob::operator[](size_t n) const {
    check(n, "location past begin"); 
    return (*data)[n];
}

// overload operator [] for  StrBlobPtr
string& StrBlobPtr::operator[](size_t n) {
    auto p = check(n, "location past begin"); 
    return (*p)[n];
}

// overload operator [] for const  StrBlobPtr
const string& StrBlobPtr::operator[](size_t n) const {
    auto p = check(n, "derefrence past end"); 
    return (*p)[n];
}

// posfix-increment opreator for StrBolbPtr
StrBlobPtr& StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


// prefix-increment opreator for StrBolbPtr
StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

// prefix-decrement for StrBlobPtr
StrBlobPtr& StrBlobPtr::operator--() {
    --curr;
    check(curr, "decrment past begin of StrBlobPtr");
    return *this;
}

// posfix-decrement for StrBlobPtr
StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}
#endif

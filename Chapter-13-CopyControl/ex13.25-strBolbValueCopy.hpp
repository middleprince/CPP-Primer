#ifndef ex13_26_StrBlobValueCopy
#define ex13_26_StrBlobValueCopy

#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlobPtr;
class StrBlob {
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

    // copy control func for value copy inplementation
    StrBlob(const StrBlob &old) : data(make_shared<vector<string> >(*old.data)) {}
    StrBlob & operator=(const StrBlob &rval);

private:
    shared_ptr<vector<string> > data;
    void check(size_type i, const string &msg) const;
};

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string & operator *() const;
    StrBlobPtr& incr();
    size_t locatoin() const {return curr;}
    
    StrBlobPtr& operator+(size_t index) {
        check(curr+index, "increment " + to_string(index) + "past StrBolbPtr");
        curr += index;
        return *this;
    }

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

StrBlob & StrBlob::operator=(const StrBlob &rvalue) {
    auto newp = make_shared<vector<string> >(*rvalue.data);
    return *this;
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

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

#endif

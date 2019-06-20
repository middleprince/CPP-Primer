#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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

private:
    shared_ptr<vector<string> > data;
    void check(size_type i, const string &msg) const;
};

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string & deref() const;
    StrBlobPtr& incr();
    size_t locatoin() const {return curr;}

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

string & StrBlobPtr::deref() const{
    auto p = check(curr, "derefrence past end"); 
    return (*p)[curr];

}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


int main(int argc, char **argv) {
    if (argc != 2)
        throw runtime_error("The argc must be 2");
    ifstream file_in(argv[1]);
    
    string text;
    StrBlob contents;

    while(getline(file_in, text ))
        contents.push_back(text);

    StrBlobPtr str_ptr(contents); 
    auto mbeg = contents.begin();
    while (mbeg.locatoin() != contents.end().locatoin()) {
        cout << mbeg.deref() << endl; 
        mbeg = mbeg.incr();
    }
    
    return 0;
}

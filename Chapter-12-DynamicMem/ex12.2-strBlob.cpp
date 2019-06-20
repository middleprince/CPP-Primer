#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class StrBlob {
 public:
    typedef vector<string>::size_type size_type;
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

int main() {
    
    return 0;
}

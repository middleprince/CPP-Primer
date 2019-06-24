#include <iostream>
#include <string>

using  std::string;
using  std::cout;
using  std::endl;

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &old) : ps(new string(*old.ps)), i(old.i) {}

    HasPtr& operator=(const HasPtr &rv);
    ~ HasPtr() {delete ps;}
private:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rv) {
    auto newps = new string(*rv.ps); 
    delete ps;
    ps = newps;
    i = rv.i;
    return *this;
}

inline
void swap(HasPtr &lval, HasPtr &rval) {
    using std::swap;
    swap(lval.ps, rval.ps);
    swap(lval.i, rval.i);
    cout<< "call swap(HasPtr &, HasPtr &)" << endl;
}







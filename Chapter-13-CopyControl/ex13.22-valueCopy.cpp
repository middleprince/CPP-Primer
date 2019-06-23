#include <iostream>
#include <string>

using namespace std;

class HasPtr {
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





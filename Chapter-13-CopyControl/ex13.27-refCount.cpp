#include <string>
#include <iostream>
#include <memory>

using namespace std;

class HasPtr {
    public:
        HasPtr(const string &s = string()) : 
            data(new string(s)), i(0), use(new size_t(1)) {}
        HasPtr(const HasPtr &old) : 
            data(old.data), i(old.i), use(old.use) {++*use;}

        HasPtr & operator=(const HasPtr &rval);
        ~HasPtr();
private:
        string *data;
        int i;
        size_t *use;
};

HasPtr & HasPtr::operator=(const HasPtr &rval) {
    ++*rval.use;
    if (--*use == 0) {
        delete data; 
        delete use;
    }
   
   data = rval.data;
   i = rval.i;
   use = rval.use;
   return  *this;
}



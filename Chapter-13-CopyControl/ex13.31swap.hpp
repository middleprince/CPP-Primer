//
//  Exercise 13.31
//
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Give your class a < operator and define a vector of HasPtrs.
//  Give that vector some elements and then sort the vector.
//  Note when swap is called.
//
//
#ifndef CP5_ex13_31swap_h
#define CP5_ex13_31swap_h

#include <iostream>
#include <string>

using  std::string;
using  std::cout;
using  std::endl;

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(const HasPtr&, const HasPtr &);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &old) : ps(new string(*old.ps)), i(old.i) {}

    HasPtr& operator=(HasPtr rv) {
        this->swap(rv);
        return *this; 
    }
    ~ HasPtr() {delete ps;}

    void swap(HasPtr &rval) {
        using std::swap;
        swap(ps, rval.ps); 
        swap(i, rval.i);
        cout << "call swap(HasPtr &)" << endl;
    }
    
    void show() {cout << *ps << endl;}

private:
    string *ps;
    int i;
};



inline
void swap(HasPtr &lval, HasPtr &rval) {
    cout<< "call swap(HasPtr &, HasPtr &)" << endl;
    lval.swap(rval);
}

bool operator<(const HasPtr &lval, const HasPtr &rval) {
    cout << "call opreator <" << endl;
    return *lval.ps < *rval.ps;
}

#endif







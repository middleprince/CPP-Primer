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

#include <iostream>
#include <string>

using  std::string;
using  std::cout;
using  std::endl;

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(const HasPtr&, const HasPtr &);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {
        cout << "call contructor" << endl; 
    }
    HasPtr(const HasPtr &old) : ps(new string(*old.ps)), i(old.i) {
        cout << "call copy constructor" << endl; 
    }

    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
        p.ps = nullptr; 
        cout << "call move constructor" << endl;
    }

    HasPtr& operator=(HasPtr rhs) {
        swap(*this, rhs);
        cout << "call assing" << endl;
        return *this; 

    }

    HasPtr & operator=(HasPtr &&) noexcept;

    ~ HasPtr() {delete ps;}

    void swap(HasPtr &lhs, HasPtr &rhs) {
        using std::swap;
        swap(lhs.ps, rhs.ps); 
        swap(lhs.i, rhs.i);
        cout << "call swap" << endl;
    }
    
    void show() {cout << *ps << endl;}

private:
    string *ps;
    int i;
};

HasPtr & HasPtr::operator=(HasPtr &&rhs) noexcept {
    if (this != &rhs) {
        ps = rhs.ps;
        i = rhs.i;   
        
        rhs.ps = nullptr;
    }
    cout << "call move assign explicitly" << endl;
    return *this;
}



int main() {
    HasPtr a("hello you");
    HasPtr b = std::move(a);
    HasPtr c = b;
    HasPtr d(std::move(c));


    cout << endl;
    b.show();
    //c.show();
}






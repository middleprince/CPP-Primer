#include "ex14.StrBlob.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main() {
    StrBlob strs{"one", "two", "three", "four"};

    StrBlobPtr ptr(strs);
    ConstStrBlobPtr cptr = strs.cbegin();
    
    cout << "Test for *ptr ,which should be one"  << endl;
    cout << *ptr << endl;

    cout << "Test for *cptr ,which should be one"  << endl;
    cout << *cptr << endl;

    cout << "Test ptr->size() " << endl;
    cout << ptr->size() << endl;

    cout << "Test cptr->size() " << endl;
    cout << cptr->size() << endl;


    return 0;
}

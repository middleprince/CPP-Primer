#include "ex14.32.SBPtr.hpp"
#include <iostream>

using std::cout;
using std::endl;


int main() {
    StrBlob strs{"one", "two", "tree"};
    auto p = strs.begin();
    PointerSB sp(&p);

    cout << "Test for Pinter-to-StrBlobPtr, sp->operator*() which should be one" << endl;
    cout << sp->operator*() << endl;

    
    return 0; 
}

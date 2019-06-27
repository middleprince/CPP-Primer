#include "ex14.16.StrBlobpp.hpp"

int main() {
    StrBlob str_test{"hello", "me", "and", "you"};
    
    for (StrBlobPtr bg = str_test.begin(); bg != str_test.end(); ++bg) {
        cout << *bg << "\n"; 
    }
    cout << endl;


    return 0;
}

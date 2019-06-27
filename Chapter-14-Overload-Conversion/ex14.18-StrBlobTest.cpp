#include "ex14.18.StrBlob.hpp"

int main() {
    StrBlob str_1{"hello", "me", "and", "you" , "a"};
    StrBlob str_2{"hello", "me", "and", "you", "b"};
    
    cout << "out put str_1 while testing for == and != " << endl;
    for (StrBlobPtr bg = str_1.begin(); bg != str_1.end(); ++bg) {
        cout << *bg << "\n"; 
    }
    cout << endl;

    cout << "# Test for str_1 > str_2" << endl;
    cout << (str_1 > str_2 ? "true" : "false") << endl;

    StrBlobPtr ptr1 = str_1.begin();
    StrBlobPtr ptr2 = str_2.begin();
    ++ptr1;
    ++ptr2;
    
    cout << "# Test for ptr1 > ptr2" << endl;
    cout << (ptr1 > ptr2 ? "true" : "false") << endl;
    cout << "# Test for ptr1 >= ptr2" << endl;
    cout << (ptr1 >= ptr2 ? "true" : "false") << endl;





    return 0;
}

#include "ex14.26.StrBlob.hpp"
#include <iostream>

int main() {
    StrBlob strs{"one", "two", "three", "four", "test"};
    StrBlobPtr ptr = strs.begin();

    cout << "Test for strs[2], it should be three" << endl;
    cout << strs[2] << endl;
    cout << "Test for ptr[3], it should be four" << endl;
    cout << ptr[3] << endl;
    return 0;
}


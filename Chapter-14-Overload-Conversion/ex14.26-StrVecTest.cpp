#include "ex14.26.StrVec.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    StrVec str_test{"one", "two", "three"};
    const StrVec cstr_test{"onec", "twoc", "threec"};

    cout << "test for str_test[2], it should be three" << endl;
    cout << str_test[2] << endl;

    cout << "test for cstr_test[2], it should be threec" << endl;
    cout << cstr_test[2] << endl;
    
    cout << "test for cstr_test[3], it should trger Error" << endl;
    cout << cstr_test[3] << endl;
    
    return 0;
}

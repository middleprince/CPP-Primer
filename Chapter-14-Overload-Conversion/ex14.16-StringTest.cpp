#include "ex14.16.Stringpp.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    String str_a{"hello it's me"};
    String str_b{"hello it's me"};
    String str_c{"hello it's you"};
    
    cout << "# test str_a == str_b" << endl;
    cout << (str_a == str_b ? "true" : "false") << endl;

    cout << "# test str_a != str_c" << endl;
    cout << (str_a != str_c ? "true" : "false") << endl;

    return 0;

}

#include <iostream>
#include "ex14.18.String.hpp"

using std::cout;
using std::endl;

int main() {
    String str_a{"you are the A"};
    String str_b{"you are the A"};
    String str_c{"you are the B"};

    cout << "Test for str_a < str_b" << endl;
    cout << (str_a < str_b ? "True" : "False") << endl;

    cout << "Test for str_a <= str_c" << endl;
    cout << (str_a <= str_c ? "True" : "False") << endl;

    cout << "Test for str_a >= str_b" << endl;
    cout << (str_a >= str_b ? "True" : "False") << endl;


    return 0;
}


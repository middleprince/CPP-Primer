#include "ex13.5String.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    String s1("hello you and me");
    cout << s1.size() << endl;
    String s2 = s1;
    
    cout << "s1 is: \n";
    cout << s1.c_str() << endl;
    
    cout << "s2 is: \n";
    cout << s2.c_str() << endl;


    return 0;
}

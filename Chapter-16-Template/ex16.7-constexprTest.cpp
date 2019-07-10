#include "ex16.7.constexpr.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int numArray[5]{1, 2, 3, 4, 5}; 
    std::string strArray[2]{"test", "string long"};

    cout << "# Test for numArray constexpr\n";
    cout << sizeOfArray(numArray) << endl;

    cout << "# Test for strArray constexpr\n";
    cout << sizeOfArray(strArray) << endl;

    return 0;

}

#include "ex16.6.begin.end.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int numArray[5]{1, 2, 3, 4, 5}; 
    std::string strArray[2]{"test", "string long"};

    cout << "# Test for numArray begin and end\n";
    for (auto p = beginMine(numArray); p != endMine(numArray); ++p)
        cout << *p << " ";
    cout << endl;

    cout << "# Test for strArray begin and end\n";
    for (auto p = beginMine(strArray); p != endMine(strArray); ++p)
        cout << *p << " ";
    cout << endl;

    return 0;

}

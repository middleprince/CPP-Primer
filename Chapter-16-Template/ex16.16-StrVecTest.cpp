#include "ex16.16.StrVec.hpp"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main() {
    Vec<string> strVec{"hello", "it's", "me", "and", "you"};
   
    // Test for size and capacity
    cout << "## Test for function size \n" 
         << "strVec size is: " << strVec.size() << endl;
   
    cout << "## Test for function capacity \n" 
         << "strVec size is: " << strVec.capacity() << endl;
   
    // Test for resize
    cout << "## Test for function resize \n"
         << "before resize, size is: " << strVec.size() << endl; 
    strVec.resize(8);
    cout << "after resize, size is: " << strVec.size()
         << "after resize, capacity is: " << strVec.capacity();
    
    
    return 0;
}

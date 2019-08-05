#include "ex16.61.make_shared.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

int main() {
    auto numPtr = ex16::make_shared<int>(2019);
    cout << "== Test for make_shared<int> ==\n" 
         << "Expected output 2019"<< endl;
    cout << "Result:\t" << *numPtr << endl;
    cout << endl;
    
    auto strPtr = ex16::make_shared<string>(10,'B');
    cout << "== Test for make_shared<stirng> ==\n" 
         << "Expected output BBBBBBBBBB"<< endl;
    cout << "Result:\t" << *strPtr << endl;
    cout << endl;
   
    return 0; 
}

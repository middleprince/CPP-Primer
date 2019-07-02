#include "ex14.45.SaleData.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main() {
    SalesData book1("little prince", 12, 23.2);

    string bookname = static_cast<string>(book1); 
    double rev  = static_cast<double>(book1);

    cout << "conversion result: book name: " << bookname << endl;
    cout << "conversion result: revenue : " << rev << endl;

    cout << "The original info" << endl;
    cout << book1 << endl;
    
    
    
    return 0;
}

#include "ex15.5.BulkQuote.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    Quote book1("jack", 13.5); 
    Bulk_Quote book2("funny book", 20, 30, 0.88);
    
    cout << "test printTotal for Quote :\n";
    printTotal(cout, book1, 10);
    cout << endl;
    
    cout << "test printTotal for BulkQuote :\n";
    printTotal(cout, book2, 40);
    cout << endl;
    return 0; 
}

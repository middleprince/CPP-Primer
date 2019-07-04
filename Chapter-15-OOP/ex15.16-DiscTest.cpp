#include "ex15.16.DiscQuote.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Quote book1("base book", 18.8);
    Bulk_Quote book2("Bulk book", 28.8, 20, 0.88);
    Up_Quote book3("Up book", 38.8, 20, 35, 0.77);

    //Disc_Quote test();

    cout << "Debug for base:\n";
    book1.debug();
    cout << endl;
    printTotal(cout, book1, 20);
    cout << endl;
    
    cout << "Debug for Bulk:\n";
    book2.debug();
    cout << endl;
    printTotal(cout, book2, 40);
    cout << endl;

    cout << "Debug for Up:\n";
    book3.debug();
    cout << endl;
    printTotal(cout, book3, 50);
    cout << endl;
}

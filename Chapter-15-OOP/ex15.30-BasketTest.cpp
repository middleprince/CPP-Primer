#include "ex15.30.Basket.hpp" 
#include <vector>
using std::vector;

#include <memory>

#include <iostream>
using std::cout;
using std::endl;

int main() {
    Basket books;
    
    Bulk_Quote book1("Book 1", 18.8, 3, 0.88);
    Bulk_Quote book2 = book1;
    Bulk_Quote book3 = book1;
    Bulk_Quote book4 = book1;

    Up_Quote book5("Book 2", 18.8, 2, 4, 0.99);
    Up_Quote book6 = book5;
    Up_Quote book7 = book5;
    Up_Quote book8 = book5;

    books.addItem(std::move(book1)); 
    books.addItem(std::move(book2)); 
    books.addItem(std::move(book3)); 
    books.addItem(std::move(book4)); 
    books.addItem(std::move(book5)); 
    books.addItem(std::move(book6)); 
    books.addItem(std::move(book7)); 
    books.addItem(std::move(book8)); 

    books.total_receipt(cout);
    
    return 0;
}

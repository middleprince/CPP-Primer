#include "ex15.16.DiscQuote.hpp" 
#include <vector>
using std::vector;

#include <memory>

#include <iostream>
using std::cout;
using std::endl;

int main() {
    vector<Quote> vecQuote;
    vector<std::shared_ptr<Quote> > vecQuoteptr;
    
    Bulk_Quote book1("Book 1", 18.8, 20, 0.88);
    Bulk_Quote book2("Book 2", 28.8, 20, 0.88);
    
    vecQuote.push_back(book1);
    vecQuote.push_back(book2);

    vecQuoteptr.push_back(std::make_shared<Bulk_Quote>(book1));
    vecQuoteptr.push_back(std::make_shared<Bulk_Quote>(book2));

    double price_total1 = 0.0;
    for (const auto &item : vecQuote) {
        price_total1 += item.netPrice(30); 
    }
    cout << "vector storing quote, total price is: " << price_total1 << endl;

    double price_total2 = 0.0;
    for (const auto &item : vecQuoteptr) {
        price_total2 += item->netPrice(30); 
    }
    cout << "vector storing quote ptr, total price is: " << price_total2 << endl;

    return 0;
}

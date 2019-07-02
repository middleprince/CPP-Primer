// define class Quote an func print_total
//
//

#ifndef ex15_3_Quote_h
#define ex15_3_Quote_h

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sale_price) 
        : bookNo(book), price(sale_price) {}
    string isbn() const {
        return bookNo; 
    }
    virtual double netPrice(std::size_t n) const {
        return n * price; 
    }

    virtual ~Quote() = default;

private:
    string bookNo;
protected:
    double  price = 0.0;
};

double printTotal(ostream &os, const Quote &item, std::size_t n) {
    double ret = item.netPrice(n);
    os << "ISBN: " <<  item.isbn() 
        << " # sold: " << n << "total due: " << ret << endl;
    return ret;
}

#endif

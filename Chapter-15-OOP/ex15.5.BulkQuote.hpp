// define class Quote an func print_total
//
//

#ifndef ex15_5_BulkQuote_h
#define ex15_5_BulkQuote_h

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

class Bulk_Quote : public Quote {
public:
    Bulk_Quote() = default;
    Bulk_Quote(const string &book, double p, std::size_t n, double d)
        : Quote(book, p), min_qty(n), discount(d) {}
    
    double netPrice(std::size_t n) const override;

private:
    std::size_t min_qty = 0;
    double discount = 0.0;

};

double Bulk_Quote::netPrice(std::size_t n) const {
    if (n >= min_qty)
        return n * (1 - discount) * price;
    else 
        return n * price;
}

double printTotal(ostream &os, const Quote &item, std::size_t n) {
    double ret = item.netPrice(n);
    os << "ISBN: " <<  item.isbn() 
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

#endif

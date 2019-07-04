// define class Quote an func print_total
//
// ex15.11 add debug() to print members.
// ex15.16 Construct Pure Abstract Base class 

#ifndef ex15_16_DiscQuote_h
#define ex15_16_DiscQuote_h

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

    virtual void debug() const {
        cout << "Book name: " << bookNo 
            << " Book price: " << price;
    }

    virtual ~Quote() = default;

private:
    string bookNo;
protected:
    double  price = 0.0;
};

//-----------------------------------------------------------------
//      Pure Abstrct class Disc_Quote
//-----------------------------------------------------------------

class Disc_Quote : public Quote {
public:
    Disc_Quote() = default;
    Disc_Quote(const string &book, double p, std::size_t n, double d)
        : Quote(book, p), quantity(n), discount(d) {}
    
    double netPrice(std::size_t) const override = 0;
    void debug() const override = 0;

protected: 
    std::size_t quantity = 0;
    double discount = 0.0;

};

//-----------------------------------------------------------------
//       class Bulk_Quote
//-----------------------------------------------------------------
class Bulk_Quote : public Disc_Quote {
public:
    Bulk_Quote() = default;
    Bulk_Quote(const string &book, double p, std::size_t n, double d)
        : Disc_Quote(book, p, n, d) {}
    
    double netPrice(std::size_t n) const override;
    void debug() const override;
};

double Bulk_Quote::netPrice(std::size_t n) const {
    if (n >= quantity)
        return n * (1 - discount) * price;
    else 
        return n * price;
}

void Bulk_Quote::debug() const {
    Quote::debug();
    cout << " min_quantity: " << quantity 
            << " discount : " << discount;
}


//-----------------------------------------------------------------
//       class Bulk_Quote
//-----------------------------------------------------------------

class Up_Quote : public Disc_Quote {
public:
    Up_Quote() = default;
    Up_Quote(const string &book, double p, std::size_t l, std::size_t h, double d)
        : Disc_Quote(book, p, l, d), max_qty(h) {}
    
    double netPrice(std::size_t n) const override;
    void debug() const override;

private:
    std::size_t max_qty = 0;
};

double Up_Quote::netPrice(std::size_t n) const {
    if (n >= quantity && n<= max_qty)
        return n * (1 - discount) * price;
    else if (n>max_qty)
        return max_qty * price * (1 - discount) + (n - max_qty) * price;
    else
        return n * price;
}

void Up_Quote::debug() const {
    Quote::debug();
    cout << " min quantity: " << quantity
        << " max_qty: " << max_qty
        << " discount: " << discount;
}

//-----------------------------------------------------------------------------
//          non-member function
//

double printTotal(ostream &os, const Quote &item, std::size_t n) {
    double ret = item.netPrice(n);
    os << "ISBN: " <<  item.isbn() 
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

#endif

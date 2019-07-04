/**
 * construct a pure virtual class.
 */ 

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

//-----------------------------------------------------------------------------
//          Base class Quote
//-----------------------------------------------------------------------------
//
class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sale_price) : bookNo(book), 
            price(sale_price) { }
    string isbn() const { return bookNo;}
    virtual double netPrice(size_t n) const{
        return price * n; 
    }
    virtual void Debug() const{
    cout << "bookNo: " << bookNo+"\n" << "price: " << price << endl;
    }
    virtual ~Quote() = default;

private:
    string bookNo;
protected:
    double price;
};

//-----------------------------------------------------------------------------
//      Pure Abstrct Class
//         Disc_quote 
//-----------------------------------------------------------------------------
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double inprice, size_t qty, double disc) 
                : Quote(book, inprice), quantity(qty), discount(disc) { } 
    //pure virtual function define the interface for different discount plans
    double netPrice(size_t ) const override = 0;
    void Debug() const override = 0;

protected:
    size_t quantity = 0;
    double discount =  0.0;
};


//-----------------------------------------------------------------------------
//          Class Bulk_quote 
//-----------------------------------------------------------------------------
//
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book_in, double price_in, size_t qty, double disc)
                : Disc_quote(book_in, price_in, qty, disc) { }
    double netPrice(size_t ) const override;
};

double Bulk_quote::netPrice(size_t num) const {
    if (num >= quantity)
        return num * (1-discount) * price;
    else 
        return num * price;
}

//-----------------------------------------------------------------------------
//          non-member function 
//-----------------------------------------------------------------------------
//
double printTotal(ostream &os, const Quote &item, size_t n) {
    double ret = item.netPrice(n);
    os << "ISBN: " << item.isbn() 
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}




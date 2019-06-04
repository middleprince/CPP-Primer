/**
 * construct a pure virtual class.
 * And define Bulk_quot_max
 */ 

#include <iostream>
#include <string>
using namespace std;

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

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double inprice, size_t qty, double disc) 
                : Quote(book, inprice), quantity(qty), discount(disc) { } 
    //pure virtual function define the interface for different discount plans
    double netPrice(size_t ) const = 0;

protected:
    size_t quantity = 0;
    double discount =  0.0;
};


// define the Bulk_quote
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book_in, double price_in, size_t qty, double disc)
                : Disc_quote(book_in, price_in, qty, disc) { }
    double netPrice(size_t ) const override;
};

class Bulk_quote_max : public Disc_quote {
public:
    Bulk_quote_max() = default;
    Bulk_quote_max(const string &book_in, double price_in, size_t qty, double disc)
                : Disc_quote(book_in, price_in, qty, disc) { }
    double netPrice(size_t ) const override;

};

double Bulk_quote::netPrice(size_t num) const {
    if (num >= quantity)
        return num * (1-discount) * price;
    else 
        return num * price;
}

double Bulk_quote_max::netPrice(size_t num) const {
    double result = 0.0;
    if (num <= quantity)
         result = num * (1-discount) * price;
    else 
        result = (num - quantity) * price + quantity * (1 - discount) * price;
    return result;
}

double printTotal(ostream &os, const Quote &item, size_t n) {
    double ret = item.netPrice(n);
    os << "ISBN: " << item.isbn() 
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
int main() {
    class Bulk_quote book1("The Drunk Man", 33.3, 30, 0.88);
    class Bulk_quote_max   book2("The Drunk Man", 33.3, 30, 0.88);
    
    cout << "#1 Test: Bulk_quote" << endl; 
    printTotal(cout, book1, 40);
    cout << "\n";

    cout << "#2 Test: Bulk_quote_max" << endl; 
    printTotal(cout, book2, 40);
    cout << "\n";
    

    return 0;
}

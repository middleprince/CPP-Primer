// define class Quote an func print_total
//
// ex15.11 add debug() to print members.
// ex15.16 Construct Pure Abstract Base class 

#ifndef ex15_30_Basket_h
#define ex15_30_Basket_h

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#include <set>

class Quote {
public:
    Quote() = default;    
    Quote(const string &book, double sale_price) 
        : bookNo(book), price(sale_price) {}
    
    Quote(const Quote &);
    Quote& operator=(const Quote &); 
    Quote(Quote &&) noexcept;
    Quote& operator=(Quote &&) noexcept; 

    virtual Quote* clone() const & {
        return new Quote(*this); 
    }

    virtual Quote* clone() const && {
        return new Quote(std::move(*this)); 
    }

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

Quote::Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) {}

Quote & Quote::operator=(const Quote &rhs) {
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
}

Quote::Quote(Quote &&rhs) noexcept 
    : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {}

Quote & Quote::operator=(Quote &&rhs) noexcept {
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    return *this;
} 

//-----------------------------------------------------------------
//      Pure Abstrct class Disc_Quote
//-----------------------------------------------------------------

class Disc_Quote : public Quote {
public:
    Disc_Quote() = default;
    Disc_Quote(const string &book, double p, std::size_t n, double d)
        : Quote(book, p), quantity(n), discount(d) {}
    
    Disc_Quote(const Disc_Quote&); 
    Disc_Quote & operator=(const Disc_Quote &);
    Disc_Quote(Disc_Quote &&) noexcept;
    Disc_Quote & operator=(Disc_Quote &&) noexcept;
    
    double netPrice(std::size_t) const override = 0;
    void debug() const override = 0;

protected: 
    std::size_t quantity = 0;
    double discount = 0.0;

};

Disc_Quote::Disc_Quote(const Disc_Quote &rhs) 
    : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {}

Disc_Quote & Disc_Quote::operator=(const Disc_Quote &rhs) {
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
}

Disc_Quote::Disc_Quote(Disc_Quote &&rhs) noexcept 
    : Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), 
    discount(std::move(rhs.discount)) {
}

Disc_Quote & Disc_Quote::operator=(Disc_Quote &&rhs) noexcept {
    Quote::operator=(std::move(rhs));
    quantity = std::move(rhs.quantity);
    discount = std::move(rhs.discount);
    return *this;
}


//-----------------------------------------------------------------
//       class Bulk_Quote
//-----------------------------------------------------------------
class Bulk_Quote : public Disc_Quote {
public:
    Bulk_Quote() = default;
    Bulk_Quote(const string &book, double p, std::size_t n, double d)
        : Disc_Quote(book, p, n, d) {}
    
    Bulk_Quote(const Bulk_Quote &);
    Bulk_Quote & operator=(const Bulk_Quote &);
    Bulk_Quote(Bulk_Quote &&) noexcept;
    Bulk_Quote & operator=(Bulk_Quote &&) noexcept;

    Bulk_Quote* clone() const & override;
    Bulk_Quote* clone() const && override;

    double netPrice(std::size_t n) const override;
    void debug() const override;
};

Bulk_Quote::Bulk_Quote(const Bulk_Quote &rhs) 
    : Disc_Quote(rhs) {}

Bulk_Quote & Bulk_Quote::operator=(const Bulk_Quote &rhs) {
    Disc_Quote::operator=(rhs);
    return *this;
}

Bulk_Quote::Bulk_Quote(Bulk_Quote &&rhs) noexcept 
    : Disc_Quote(std::move(rhs)) {
}

Bulk_Quote & Bulk_Quote::operator=(Bulk_Quote &&rhs) noexcept {
    Disc_Quote::operator=(std::move(rhs));
    return *this;
}

Bulk_Quote* Bulk_Quote::clone() const & {
    return new Bulk_Quote(*this);
}

Bulk_Quote* Bulk_Quote::clone() const && {
    return new Bulk_Quote(std::move(*this));
}

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
    Up_Quote()= default;
    Up_Quote(const string &book, double p, std::size_t l, std::size_t h, double d)
        : Disc_Quote(book, p, l, d), max_qty(h) {}
    
    Up_Quote(const Up_Quote &);
    Up_Quote & operator=(const Up_Quote &);
    Up_Quote(Up_Quote &&) noexcept;
    Up_Quote & operator=(Up_Quote &&) noexcept;

    Up_Quote* clone() const & override;
    Up_Quote* clone() const && override;

   double netPrice(std::size_t n) const override;
    void debug() const override;

private:
    std::size_t max_qty = 0;
};

Up_Quote::Up_Quote(const Up_Quote &rhs) 
    : Disc_Quote(rhs), max_qty(rhs.max_qty) {}

Up_Quote & Up_Quote::operator=(const Up_Quote &rhs) {
    Disc_Quote::operator=(rhs);
    max_qty = rhs.max_qty;
    return *this;
}

Up_Quote::Up_Quote(Up_Quote &&rhs) noexcept 
    : Disc_Quote(std::move(rhs)), max_qty(std::move(rhs.max_qty)) {}

Up_Quote & Up_Quote::operator=(Up_Quote &&rhs) noexcept {
    Disc_Quote::operator=(std::move(rhs));
    max_qty = std::move(rhs.max_qty);
    return *this;
}

Up_Quote* Up_Quote::clone() const & {
    return new Up_Quote(*this);
}

Up_Quote* Up_Quote::clone() const && {
    return new Up_Quote(std::move(*this));
}

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
//-----------------------------------------------------------------------------

double printTotal(ostream &os, const Quote &item, std::size_t n) {
    double ret = item.netPrice(n);
    os << "ISBN: " <<  item.isbn() 
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}


//-----------------------------------------------------------------------------
//      class Basket
//-----------------------------------------------------------------------------

class Basket {
public:
    void addItem(Quote &);
    void addItem(Quote &&);
    double  total_receipt(ostream &) const;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, 
            const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn(); 
    }
    
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};

};

void Basket::addItem(Quote &sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone()));
}

void Basket::addItem(Quote &&sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
}

double Basket::total_receipt(ostream &os) const {
    double sum = 0.0;
    
    for (auto item = items.cbegin(); item != items.cend(); 
            item = items.upper_bound(*item)) {
        sum += printTotal(os, **item, items.count(*item)); 
    }
    return sum;
}
#endif

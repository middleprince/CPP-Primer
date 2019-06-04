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


class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &name, double sale_price, size_t qty, double disc) : 
                Quote(name, sale_price), min_qty(qty), discount(disc) {}
    double netPrice(size_t ) const override;
    void Debug() const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;

};

double printTotal(ostream &os, const Quote &item, size_t n) {
    double ret = item.netPrice(n);
    os << "ISBN: " << item.isbn() 
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

double Bulk_quote::netPrice(size_t n) const {
    if (n >= min_qty)
        return  n * (1 - discount) * price;
    else
        return n * price;

}
void Bulk_quote::Debug() const {
    Quote::Debug(); 
    cout << "discount book numbers: " << min_qty << "\n"
        << "discount percentage: " << discount << "\n\n";

}


int main() {
    Quote item1("The sun also rise", 43.3);
    Bulk_quote item2("Bad Blode", 55, 30, 0.7);
    Quote *bp = &item1;
    Quote &dp = item2;

    cout << "#1 Test printTotal function:" << endl;
    printTotal(cout, item1, 20);
    printTotal(cout, item2, 20);

    cout << "#2 Test  vortual function:" << endl;
    bp->Debug(); 
    dp.Debug();

    return 0;


}

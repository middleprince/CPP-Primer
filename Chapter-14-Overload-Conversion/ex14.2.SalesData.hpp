
#ifndef ex14_2_SalesData_h
#define ex14_2_SalesData_h

#include <iostream>
#include <string>
#include <functional>

// add forward declaraton for template hash which will specialize
//   hash<SaleData> in chapter 16 ex16.62

//template <class T> class std::hash;

class SalesData {
    friend std::istream & operator>>(std::istream &, SalesData &);
    friend std::ostream & operator<<(std::ostream &, const SalesData &);
    friend SalesData operator+(const SalesData &, const SalesData &); 

    friend bool operator==(const SalesData&, const SalesData&);
    friend bool operator!=(const SalesData&, const SalesData&);
    friend class std::hash<SalesData>;

public:
    SalesData(const std::string &s, unsigned n, double p)
        : bookNo(s), unit_sold(n), revenue(n * p) {}
    SalesData() : SalesData("", 0, 0.0) {}
    SalesData(const std::string &s) : SalesData(s, 0, 0.0) {}
    SalesData(std::istream &is);

    SalesData & operator+=(const SalesData &);
    std::string isbn() const {return bookNo;}

private:
    std::string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
    
    double avg_price() const;

};

inline double SalesData::avg_price() const  {
    return (unit_sold ? revenue / unit_sold : 0 ) ;
}

SalesData::SalesData(std::istream &is) {
    double price;
    is >> bookNo >> unit_sold >> price; 
    revenue = unit_sold * price;
}

SalesData & SalesData::operator+=(const SalesData &rhs) {
    if (bookNo == rhs.bookNo) {
        unit_sold += rhs.unit_sold;
        revenue += rhs.revenue; 
    }
    return *this;
} 

std::istream & operator>>(std::istream &is, SalesData &item) {
    double price;
    is >> item.bookNo >> item.unit_sold >> price;    
    if (is)
        item.revenue = item.unit_sold * price;
    else 
        item = SalesData();
    return is;
}

std::ostream & operator<<(std::ostream &os, const SalesData &item) {
    os << item.bookNo << " " << item.unit_sold << " " 
        << item.revenue << " " << item.avg_price() << std::endl;
    return os;
}

SalesData operator+(const SalesData &item_a, const SalesData &item_b) {
    SalesData result = item_a;
    result += item_b;
    return result;
}

inline 
bool operator==(const SalesData &lhs, const SalesData &rhs) {
    return lhs.isbn() == rhs.isbn() &&
           lhs.unit_sold == rhs.unit_sold &&
           lhs.revenue == rhs.revenue;
}
 
inline 
bool operator!=(const SalesData &lhs, const SalesData &rhs) {
    return !(lhs == rhs);
}

#endif


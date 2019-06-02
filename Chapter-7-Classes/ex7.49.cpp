/** 
 * The exercise about class and some attributes
 *
 */

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::endl;

class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const string &name, unsigned num, double priceIn) : bookNo(name), 
                units_sold(num), renvenue(priceIn * num) { }
    Sales_data(const string &name) : bookNo(name) { }
    Sales_data(istream &is) {
        read(is, *this);
    }

    inline string isbn () const ;
    Sales_data& combine(Sales_data);
    Sales_data& combineRefe(Sales_data&);

    // overload const this 
    const Sales_data& combineRefeConst(const Sales_data &rhs) const {
        doCombineRefeConst(rhs);
        return *this;
    }
    Sales_data& combineRefeConst(const Sales_data &rhs) {
        doCombineRefeConst(rhs);
        return *this;
    }
    
    static istream &read(istream &is, Sales_data &item);
    static ostream &print(ostream &os, const Sales_data &item);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double renvenue = 0.0;
    
    double avgPrice() const;
    void doCombineRefeConst(const Sales_data &rhs) const;
    
};

string Sales_data::isbn() const {
    return bookNo; 
}

Sales_data& Sales_data::combine(Sales_data rhs) {
    this->units_sold += rhs.units_sold;
    this->renvenue += rhs.renvenue;
    cout << "in combie" << std::endl;
    return *this;
}
Sales_data& Sales_data::combineRefe(Sales_data &rhs) {
    this->units_sold += rhs.units_sold;
    this->renvenue += rhs.renvenue;
    cout << "int conbineRefe" << std::endl;
    return *this;
}
// The overload of const this
void Sales_data::doCombineRefeConst(const Sales_data &rhs) const {
    cout << "Can not write the const obj's member, and the caller ibsn is : " 
        << rhs.bookNo << endl;
    cout << "in combineRefeConst" << std::endl;
}

double Sales_data::avgPrice() const {
    return units_sold ? renvenue / units_sold : 0.0;
}

istream & Sales_data::read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.renvenue = price * item.units_sold;
    return is;
}

ostream& Sales_data::print(ostream &os, const Sales_data &item) {
    os << item.bookNo << " " << item.units_sold << " " << item.renvenue << 
        " " << item.avgPrice() << endl;
    return os;
}

int main() {
    Sales_data item1;
    Sales_data item2("The Tree", 500, 12.5);
    const Sales_data item_const;
    //Sales_data item3("Fire Fly");
    //Sales_data item4(std::cin);
    string s("The string");
    item1.combine(s);
    Sales_data::print(cout, item1); 
   
    item2.combine(s); 
    Sales_data::print(cout, item2);
    
    item_const.combineRefeConst(s);
    Sales_data::print(cout, item_const);

    //Sales_data::print(cout, item3);
    
    //Sales_data::print(cout, item4);
    
   return 0; 

}

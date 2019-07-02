// exercise aout ex14.52 match and conversion match problem. 
//

#include <iostream>

class SmallInt {
    friend 
    SmallInt operator+(const SmallInt &, const SmallInt &);

    int val;
    
public:
    SmallInt(int a = 0) : val(a) {}
    operator int() {return val;} 
};

class LongDouble {
    friend 
    LongDouble operator+(const LongDouble &, const double);
    double dval;
public:
    LongDouble(double a = 0.0) : dval(a) {}
    operator double() {return dval;} 
    operator int() {return static_cast<int>(dval);} 

    LongDouble operator+(const SmallInt &a) {
        this->dval += a;
    }
};

SmallInt operator+(const SmallInt &a, const SmallInt &b) {
    SmallInt ret(a.val + b.val);
    return ret;
}

LongDouble operator+(const LongDouble &a, const double b) {
    LongDouble ret(a.dval + b);
    return ret; 
}

int main() {
    SmallInt si;
    LongDouble ld;

    // this will be ambiguous for 
    //ld = si + ld; 
    //
    ld = ld + si;
    return 0;
}

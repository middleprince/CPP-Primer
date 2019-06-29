#ifndef ex14_35_PrintStr_h
#define ex14_35_PrintStr_h

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;
using std::cin;

class PrintString {
public:
    PrintString(istream &i = cin) : is(i) {}
    string operator ()() {
        string strs;
        getline(is, strs);  
        return is ? strs : string();
    }

private:
    istream &is;
};


#endif

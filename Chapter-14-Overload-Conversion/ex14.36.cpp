#include "ex14.35.PrintStr.hpp"

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main() {
    PrintString getIn;
    vector<string> stringVec;
    string temp;
    while ( (temp = getIn()) != string()) {
       stringVec.push_back(temp); 
    
    } 

    for (const auto &item : stringVec)
        cout << item << endl;
    return 0;
}

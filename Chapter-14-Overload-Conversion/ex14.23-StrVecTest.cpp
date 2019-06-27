#include "ex14.23.StrVec.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    StrVec a = {"hello", "it's", "the", "initializer_list", "test"}; 

    for (const auto &item : a)
        cout << item << endl;
    return 0;
}

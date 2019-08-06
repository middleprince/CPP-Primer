#include "ex16.62.hashSalesData.hpp"
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;
using std::hash;
using std::unordered_multiset;

int main() {
    unordered_multiset<SalesData> sale_dataSet;
    sale_dataSet.emplace("More efective C++", 12, 40.7);
    sale_dataSet.emplace("The C++ programming language", 10, 140.7);
    sale_dataSet.emplace("Algorithm", 30, 80.7);

    for (const auto &item : sale_dataSet) {
        cout << "the hash of the book << " << item.isbn() << " >>"
             << " is :\n0x" << std::hex << hash<SalesData>()(item)
             << endl;
    }
    
    return 0;
    
}

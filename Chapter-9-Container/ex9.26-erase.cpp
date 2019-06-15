#include <list>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    int ia[] = {0, 1, 1, 2, 3, 4, 5, 5, 6, 9};
    vector<int> va_vec;
    list<int> va_list;
    // pointer is also a type iterator
    int *ib = begin(ia), *ie = end(ia); 
    //assign ia th vec and list
    va_vec.assign(ib, ie);
    va_list.assign(ib, ie);
    //for (int *i=begin(ia); i!=end(ia); ++i) {
    //    va_vec.push_back() 
    
    //}
    
    auto p = va_vec.begin();
    while (p != va_vec.end()) {
        if (*p%2 != 0) 
            ++p;
        else 
            p = va_vec.erase(p);
    }
    
    auto pl = va_list.begin();
    while (pl != va_list.end()) {
        if (*pl%2 == 0) 
            ++pl;
        else 
            pl = va_list.erase(pl);
    }

    cout << "#Test output for vec: \n";
    for (const auto &item : va_vec)
        cout << item << " "; 
    cout << "\n";
    
    cout << "#Test output for list: \n";
    for (const auto &item : va_list)
        cout << item << " "; 
    cout << "\n";
    return 0;
}

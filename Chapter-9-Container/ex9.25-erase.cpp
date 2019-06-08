#include <list>
#include <iostream>

using namespace std;

void print(const list<int> &to_print) {
    for (const auto &item : to_print)
        cout << item << " ";
    cout << endl;
}

int main() {
    list<int> a{1, 2, 3};
    cout << "#Test 1: \n";
    cout << "The original list is: ";
    print(a);
    
    // range(a, a)
    cout << "#Test 2 range(elem, elem): \n";
    a.erase(++a.begin(), ++a.begin());
    print(a);

    // the rage is (off-the-end, off-the-end)
    cout << "#Test 3 range(elem.end(), elem.end()): \n";
    a.erase(a.end(), a.end());
    print(a);
    
    return 0; 
}

#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> a{2};
    if (!a.empty()) {
        // front() will return the reference of the first elemnt
        auto val1 = *a.begin(), val2 = a.front(); 
        auto last = a.end();
        auto val3 = *(--last);
        // likeeise back() will return the reference of the last emlment
        auto val4 = a.back();

        cout << "#Test 1: \n";
        cout << "val1 is: " << val1 << endl;
        cout << "val2 is: " << val2 << endl;
        cout << "val3 is: " << val3 << endl;
        cout << "val4 is: " << val4 << endl;

    
    }
    return 0;
}

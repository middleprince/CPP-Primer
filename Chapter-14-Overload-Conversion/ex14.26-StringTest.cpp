#include "ex14.26.String.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::size_t;

int main() {
    String a("012345678");

    for (size_t i = 0; i != a.size(); ++i)
        cout << a[i] << endl;
    return 0;
}


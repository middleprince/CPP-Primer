#include "ex14.27.StrBlob.hpp"

int main() {
    StrBlob strs{"hello", "me", "you", "four"};
    
    for (auto p = strs.begin(); p != strs.end(); ++p)
        cout << *p << endl;
    return 0;
}

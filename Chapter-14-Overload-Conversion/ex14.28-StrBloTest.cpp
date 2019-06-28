#include "ex14.28.StrBlob.hpp"

int main() {
    StrBlob strs{"one", "two", "three", "four"};
    StrBlobPtr p = strs.begin();

    cout << " Test output *(p+2), which should be three" << endl;
    cout << *(p+2) << endl;
    
    cout << "Test  *(p-2), which should be : one" << endl;
    cout << *(p-2) << endl;
    
    cout << "Test out of index, *(p+5)" << endl;
    cout << *(p+5) << endl;

        return 0;
}

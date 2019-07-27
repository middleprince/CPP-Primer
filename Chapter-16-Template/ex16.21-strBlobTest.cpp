#include "ex16.21.strBlob.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    Blob<string> theStrings{"hello", "me", "you"};
    Blob<int> theInts{1, 3, 4, 5, 6};
    
    theStrings.push_back(std::move("king"));
    theInts.push_back(100);

    BlobPtr<string> strPtr(theStrings);
    BlobPtr<int> intPtr(theInts);

    cout << *strPtr << endl;

    //for (auto item = theStrings.begin(); item != theStrings.end(); ++item)
    //    cout << *item << " ";
    //cout << endl;

    return 0;
}

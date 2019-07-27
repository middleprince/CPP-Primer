#include "ex16.21.strBlob.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    Blob<string> theStrings{"hello", "me", "you"};
    theStrings.push_back(std::move("king"));

    Blob<string> theStringscp = theStrings;

    for (auto item = theStrings.cbegin(); item != theStrings.cend(); ++item)
        cout << *item << " ";
    cout << endl;
    

    for (auto item = theStringscp.cbegin(); item != theStringscp.cend(); ++item)
        cout << *item << " ";
    cout << endl;
    

    return 0;
}

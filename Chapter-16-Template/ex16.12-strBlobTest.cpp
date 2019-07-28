#include "ex16.12.strBlob.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    Blob<string> theStrings{"hello", "me", "you"};
    theStrings.push_back(std::move("king"));
    
    Blob<int> theInts{100, 200, 300};

    // test for copy constructor
    Blob<string> theStringscp = theStrings;

    // for move copy constructor
    Blob<string> theString_moving = std::move(theStrings);
    
    cout << "## Test for const iterator for theInts" << endl;
    for (auto item = theInts.cbegin(); item != theInts.cend(); ++item)
        cout << *item << " ";
    cout << endl;

    cout << "## Test for const iterator for theString" << endl;
    for (auto item = theStrings.cbegin(); item != theStrings.cend(); ++item)
        cout << *item << " ";
    cout << endl;
    
    cout << "## Test for const iterator for theStringscp" << endl;
    theStringscp.push_back("copy");
    for (auto item = theStringscp.cbegin(); item != theStringscp.cend(); ++item)
        cout << *item << " ";
    cout << endl;
   
    cout << "## Test for const iterator for theString_moving" << endl;
    for (auto item = theString_moving.cbegin(); item != theString_moving.cend(); ++item)
        cout << *item << " ";
    cout << endl;

    cout << "## Test for iterator " << endl;
    for (auto &item : theInts) { 
       item *= 2;
       cout << item << " ";
    }
    cout << endl;

    //Test for front 
    cout << "## Test for front and back items of theStrings" << endl;
    cout << theStrings.front() << endl;
    cout << theStrings.back() << endl;

    // Test for operator []
    cout << "## Test for operator [2] on theStrings" << endl;
    cout << theStrings[2] << endl;

    // for const constructor
    const Blob<string> const_theString(theStrings);
    auto constItem = const_theString.cbegin();
    cout << "## Test for const iterator and operator[3] on const_theString" << endl;
    cout << constItem[3] << endl;
    
    return 0;
}

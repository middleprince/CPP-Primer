// exerciser 13.50
//
// the move constructor will be call 1 +  n times,for which String obj move
// into vecto will call move constructor; then vector to rearrge the members
// by dictionaty older will use n times(n members in vector) the move constr-
// ctor. 
// 
// copy constructor will be call 1 times, which initailize the String object.
//
// 
#include "ex13.49moveString.hpp"
#include <vector>

using std::vector;

int main() {
    vector<String> vecS;
    vecS.push_back("hello");
    vecS.push_back("me");
    vecS.push_back("yo");

    return 0;
}

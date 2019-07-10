#include "ex16.4.find.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main() {
    vector<int> vNums{2, 3, 4, 5, 6, 12};
    list<string> lStrs{"hello", "you", "and", "me"};

    auto item = findMine(vNums.cbegin(), vNums.cend(), 12);
    cout << "# test for vector find: " << *item << endl;

    auto item2 = findMine(lStrs.cbegin(), lStrs.cend(), "me");
    cout << "# test for vector find: " << *item2 << endl;

    return 0;
}

#include "ex14.16.StrVecpp.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    StrVec vec1{"hello", "you", "me"};
    StrVec vec2{"hello", "you", "me"};
    StrVec vec3{"hello", "you", "me", "haha"};

    cout << "#Test for vec1 == vec2" << endl;
    cout << (vec1 == vec2 ? "true" : "false") << endl;

    cout << "#Test for vec1 != vec3" << endl;
    cout << (vec1 != vec3 ? "true" : "false") << endl;



    return 0;
}

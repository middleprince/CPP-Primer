#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;


class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
    
    Foo sortedLv() const &;

private:
    vector<int> data;

};

Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sortedLv() const & {
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return *this;
}


Foo Foo::sorted() const & {
    cout << "sorted V 1" << endl;
    Foo ret(*this);
    
    return ret.sorted();
}

//Foo Foo::sorted() const & {
//    cout << "sorted V 2" << endl;
//    return Foo(*this).sorted();
//}

int main() {
    Foo a;
    a.sorted();
    
   return 0;

}


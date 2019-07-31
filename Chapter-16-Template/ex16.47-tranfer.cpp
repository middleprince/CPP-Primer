#include <iostream>
#include <utility>
using std::cout;
using std::endl;

void fcn(int a, int &b) {
    std::cout << a << " " << ++b << std::endl;
}
void g(int &&i, int &j) {
    cout << i << " " << j << endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1)); 
}

int main() {
    // test for lvalue
    int a = 10;
    
    cout << "## Test for lvalue flip, expected:  8 11\n" << endl;
    cout << "result: ";
    flip(fcn, a, 8);

    cout << "## Test for rvalue flip, expected:  3 11\n" << endl;
    cout << "result: ";
    flip(g, a, 3);
    
    return 0;
}

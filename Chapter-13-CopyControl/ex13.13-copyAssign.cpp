#include <iostream>
#include <vector>

using namespace std;

struct X {
    X () {cout << "X()" << endl;}
    X (const X&) {cout << "X(const X&)" << endl;}
    void  operator=(const X&) {cout << "X assign" << endl;}
    
   ~X() {cout << "~X()" << endl;}
    
};

void testFuncRef(const X& para) {
    cout << "pass by refrence" << endl;
}

void testFuncVal(const X para) {
    cout << "pass by value" << endl;
}

int main() {

    cout << "#1 test for refrence augment pass" << endl;
    X a;
    testFuncRef(a);

    cout << "#2 test for no-refrence augment pass" << endl;
    testFuncVal(a);

    cout << "#3 test for dynamicly allocate" << endl;
    auto dx = new X;
    delete dx;
    
    cout << "#4 test for container" << endl;
    vector<X> vx{}; 
    
    return 0;
}

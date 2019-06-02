#include <iostream>

using std::cout;
using std::endl;

void f() {
    cout << "This is f()" << endl;
}

void f(int a) {
    cout << "This is f(int): " << a << endl;
}

void f(int a, int b) {
    cout << "This is f(int, int): " << a << b << endl;
}

void f(double a, double b = 3.14) {
    cout << "This is f(double, double = 3.14): " << a << b << endl;
}

int main() {
   //f(2.56, 42);
   f(42);
   f(42, 0);
   f(2.56, 3.14);
    
  return 0; 
}


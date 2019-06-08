// constexpr and pionter

#include <iostream>

// the variable which is file range have to be declared as const or extern
constexpr int null = 0; 
const constexpr int *p = &null; // constexpr *pointer: top-level const 

int main() {
    int a = 10;
    std::cout << a;

}

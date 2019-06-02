/**
 * The ability of the default constructor
 * how to address the error whitout default cosntructot
 */

#include <iostream>
#include <vector>

class NoDefault {
public:
    //NoDefault() = default; 
    NoDefault (const int &num) : mem(num) { }
    int mem;
};

struct C {

    private: 
    NoDefault my_mem;
};

int main() {
    std::vector<NoDefault> vec(10);
    std::vector<C> vecC(10);
    vec[0].mem = 200;
    std::cout << vec[0].mem << std::endl;
    return 0;
}

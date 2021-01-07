/**
 * The ability of the default constructor
 * how to address the error whitout default cosntructot
 */

#include <iostream>
#include <vector>
#include <string>


class NoDefault {
public:
    //NoDefault() = default; 
    NoDefault (const int &num) : mem(num) { }
    NoDefault (const std::string &strs) : the_strs(strs) { }

    int mem{1};
    std::string the_strs{"123"};
};

struct C {

    private: 
    NoDefault my_mem;
};

int main() {
    std::vector<NoDefault> vec(10);
    //std::vector<C> vecC(10);
    vec[0].mem = 200;
    std::cout << vec[0].mem << std::endl;
    return 0;
}

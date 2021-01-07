#include <vector>
using std::vector;

class Example {
public:     
    static constexpr double rate = 6.5;
    //  static member must be initialize out of the class, or 
    //  define as static constexpr or const double rate = 6.5;
    //
    static const int vecSize = 20;
    
    static vector<double> vec;
    // non-static members can not be used as default arguments.

};

// declareation of static member must be out of function
vector<double> Example::vec;
const double Example::rate;

int main() {
    return 0;
}

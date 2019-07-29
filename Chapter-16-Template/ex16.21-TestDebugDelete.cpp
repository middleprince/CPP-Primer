#include "ex16.21.DebugDelete.hpp"
int main() {
    double *p = new double(10); 
    DebugDelete d;
    d(p);

    // using DebugDelete for unique_ptr
    std::unique_ptr<int, DebugDelete> sp(new int, DebugDelete());
    
    return 0;
}

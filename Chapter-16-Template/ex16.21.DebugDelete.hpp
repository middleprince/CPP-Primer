#ifndef ex16_21_DebugDelete_h
#define ex16_21_DebugDelete_h
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::ostream;

class DebugDelete {
public:
    DebugDelete(ostream & os_in = std::cerr) : os(os_in) {}
    template <typename T>
    void operator() (T *p) const {
        cout << "delete unique_ptr" << endl;
        delete p;
    }
    
private:
    ostream &os;
};

#endif

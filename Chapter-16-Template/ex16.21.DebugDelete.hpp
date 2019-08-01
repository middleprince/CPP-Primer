#ifndef ex16_21_DebugDelete_h
#define ex16_21_DebugDelete_h
#include <iostream>
#include <memory>

class DebugDelete {
public:
    DebugDelete(std::ostream & os_in = std::cerr) : os(os_in) {}
    template <typename T>
    void operator() (T *p) const {
        std::cout << "delete unique_ptr" << std::endl;
        delete p;
    }
    
private:
    std::ostream &os;
};

#endif

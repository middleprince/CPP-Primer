#ifndef ex16_53_variadicPrint_hpp
#define ex16_53_variadicPrint_hpp

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ostream;

template <typename T>
ostream & print(ostream &os, const T &t) {
    return os << t;
}

template <typename T, typename... Args>
ostream & print(ostream &os, const T& t, const Args&... rest) {
    os << t << " "; 
    return print(os, rest...);

}

#endif



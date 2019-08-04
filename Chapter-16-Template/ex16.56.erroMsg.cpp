#include "ex16.53.variadicPrint.hpp"
#include "ex16.48.debugRep.hpp"

template <typename... Args>
ostream & erroMsg(ostream & os, const Args&... rest) {
    return print(os, debugRep(rest)...);
}

int main() {
    erroMsg(std::cerr, "one error", 12, "other");
    return 0;
}

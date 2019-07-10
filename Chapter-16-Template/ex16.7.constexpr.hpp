#ifndef ex16_7_constexpr_h
#define ex16_7_constexpr_h

template<typename Elem, unsigned N>
constexpr unsigned sizeOfArray(const Elem (&data)[N]) {
    return N;
}


#endif

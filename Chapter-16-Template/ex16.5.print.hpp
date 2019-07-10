#ifndef ex16_5_print_h
#define ex16_5_print_h

#include <iostream>
using std::cout;
using std::endl;

template<typename Emlem, unsigned N> 
void print(Emlem (&data)[N]) {
    for (unsigned i = 0; i != N; ++i)
        cout << data[i] << "\n";
    cout << endl;
}

#endif

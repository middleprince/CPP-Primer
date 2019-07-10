#ifndef ex16_6_begin_end_h
#define ex16_6_begin_end_h

template<typename Elem, unsigned N>
Elem* beginMine(Elem (&data)[N]) {
    return data;
}

template<typename Elem, unsigned N>
Elem* endMine(Elem (&data)[N]) {
    return (data + N);
}
#endif

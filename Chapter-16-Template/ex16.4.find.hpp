#ifndef ex16_4_find_h
#define ex16_4_find_h

template<typename Iter, typename Elem>
Iter findMine(Iter begin, Iter end, const Elem &data) { 
    for (; begin != end; ++begin) {
        if (*begin == data)
            break; 
    }
    return begin;
}

#endif

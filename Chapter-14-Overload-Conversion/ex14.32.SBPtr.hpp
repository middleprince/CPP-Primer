#ifndef ex14_32_SBPtr_h
#define ex14_32_SBPtr_h

#include "ex14.StrBlob.hpp"

class PointerSB {
public:
    PointerSB() : ptr(nullptr) {}  
    PointerSB(StrBlobPtr *s) : ptr(s) {}

    StrBlobPtr & operator*() const;
    StrBlobPtr * operator->();

private:
    StrBlobPtr *ptr;
};

inline StrBlobPtr & PointerSB::operator*() const {
    return *(this->ptr); 
}

inline StrBlobPtr * PointerSB::operator->()  {
    return & this->operator*();
}

#endif

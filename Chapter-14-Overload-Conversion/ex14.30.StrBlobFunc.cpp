#include "ex14.30.StrBlob.hpp"
#include <algorithm>

//---------------------------------------------------------
//  Member function in StrBlob
//
//--------------------------------------------------------

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

ConstStrBlobPtr StrBlob::cbegin() const{
    return ConstStrBlobPtr(*this); 
}

ConstStrBlobPtr StrBlob::cend() const{
    auto ret = ConstStrBlobPtr(*this, data->size());
    return ret;
}

//---------------------------------------------------------
//      copy assignment constructor
//      move assigment constructor 
//      For StrBolb
//--------------------------------------------------------
StrBlob& StrBlob::operator=(const StrBlob &rhs) {
    data = make_shared<vector<string> >(*rhs.data);
    return *this;
}

StrBlob& StrBlob::operator=(StrBlob &&rhs) noexcept {
    if (this != &rhs) {
        data = std::move(rhs.data); 
        rhs.data = nullptr;
    }
    return *this;
}

//---------------------------------------------------------
// StrBlob operator
//
//--------------------------------------------------------

// overload == for StrBlob
bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return (*lhs.data == *rhs.data);
}

// overload != for StrBlob
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

// overload < for StrBlob
bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
                                        rhs.data->begin(), rhs.data->end());

}

// overload > for StrBlob
bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
    return rhs < lhs;
}

// overload <= for StrBlob
bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs > rhs);
}

// overload >= for StrBlob
bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs > rhs);
}


//---------------------------------------------------------
// StrBlobPtr operator
//
//--------------------------------------------------------

// overload == for StrBlobPtr
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return (lhs.curr == rhs.curr);
}
// overload != for StrBlobPtr
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}


// overload < for StrBlobPtr
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr < rhs.curr;
}

// overload > for StrBlobPtr
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr > rhs.curr;
}

// overload <= for StrBlobPtr
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs > rhs);
}

// overload >= for StrBlobPtr
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs < rhs);
}

//---------------------------------------------------------
//      CosntStrBlobPtr operator
//
//--------------------------------------------------------

// overload == for ConstStrBlobPtr
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return (lhs.curr == rhs.curr);
}
// overload != for ConstStrBlobPtr
bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return !(lhs == rhs);
}


// overload < for ConstStrBlobPtr
bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return lhs.curr < rhs.curr;
}

// overload > for ConstStrBlobPtr
bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return lhs.curr > rhs.curr;
}

// overload <= for ConstStrBlobPtr
bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return !(lhs > rhs);
}

// overload >= for ConstStrBlobPtr
bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return !(lhs < rhs);
}




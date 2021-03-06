#ifndef ex16_29_BlobSmartPtr_hpp
#define ex16_29_BlobSmartPtr_hpp

#include "ex16.28.SmartPointer.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>

template <typename> class BlobPtr;
template <typename> class ConstBlobPtr;
template <typename> class Blob;

// -----------------------------------------------------------------------------
// 
//      template strBlob
//
// -----------------------------------------------------------------------------

template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator!=(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator<(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator>(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator<=(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator>=(const Blob<T> &, const Blob<T> &);

template <typename T> 
class Blob {
    friend class BlobPtr<T>;
    friend class ConstBlobPtr<T>;
    
    friend bool operator== <T>(const Blob<T> &, const Blob<T> &);
    friend bool operator!= <T>(const Blob<T> &, const Blob<T> &);

    friend bool operator< <T>(const Blob<T> &, const Blob<T> &);
    friend bool operator> <T>(const Blob<T> &, const Blob<T> &);
    
    friend bool operator<= <T>(const Blob<T> &, const Blob<T> &);
    friend bool operator>= <T>(const Blob<T> &, const Blob<T> &);
public:
    typedef typename std::vector<T>::size_type size_type;

    Blob() : data(new std::vector<T>()) {}
    Blob(std::initializer_list<T> il) : data(new std::vector<T>(il)) {}
    
    // for construct by a pair of iterators
    template <typename I>
    Blob(I a, I b) 
        : data(new std::vector<T>(a, b)) {}
    
    Blob(const Blob<T> &lhs) : data(new std::vector<T>(*lhs.data)) {}
    Blob & operator=(const Blob<T> &);
    
    Blob(const Blob<T> &&rhs) noexcept : data(std::move(rhs.data)) {}
    Blob & operator=(const Blob<T> &&) noexcept;
    
    size_type size() const {return data->size(); }
    bool empty() const {return data->empty(); }

    void push_back(const T &t) {data->push_back(t); }
    void push_back(const T &&t) {data->push_back(std::move(t)); }
    void pop_back();

    BlobPtr<T> begin();
    BlobPtr<T> end();

    ConstBlobPtr<T> cbegin() const;
    ConstBlobPtr<T> cend() const;

    T& front();
    T& back();
    const T& front ()const;
    const T& back ()const;

    T& operator[] (size_type n);
    const T& operator[] (size_type n) const;

private:
    // simple SharePtr defined
    SharedPtr<std::vector<T> > data;
    void check(size_type, const std::string &) const;
};

//-----------------------------------------------------------------------------
//      friend function 
//-----------------------------------------------------------------------------

template <typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *lhs.data = *rhs.data; 
}

template <typename T> bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T> bool operator<(const Blob<T> &lhs, const Blob<T> &rhs) {
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
                                        rhs.data->begin(), rhs.data->end());
}

template <typename T> bool operator>(const Blob<T> &lhs, const Blob<T> &rhs) {
    return (rhs < lhs);
}

template <typename T> bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(rhs < lhs);
}

template <typename T> bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs < rhs);
};

//-----------------------------------------------------------------------------
//     Class StrBlob memberfunction  function 
//
//-----------------------------------------------------------------------------

template <typename T>
Blob<T> & Blob<T>::operator=(const Blob<T> &lhs) {
    data = new std::vector<T>(*lhs.data); 
    return *this;
}

template <typename T>
Blob<T> & Blob<T>::operator=(const Blob<T> &&rhs) noexcept {
    if (this != &rhs) {
        data = std::move(rhs.data); 
        rhs.data = nullptr;
    }
    
    return *this;
}

template <typename T>
BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(*this);
}

template <typename T>
BlobPtr<T> Blob<T>::end() {
    return BlobPtr<T>(*this, data->size());
}

template <typename T>
ConstBlobPtr<T> Blob<T>::cbegin() const {
    return ConstBlobPtr<T>(*this);
}

template <typename T>
ConstBlobPtr<T> Blob<T>::cend() const {
    return ConstBlobPtr<T>(*this, data->size());
}

template <typename T>
inline void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) 
        throw std::out_of_range(msg);
}

template <typename T>
inline void Blob<T>::pop_back() {
    check(0, "back on empty blob");   
    data->pop_back();
}

template <typename T>
inline T& Blob<T>::front() {
    check(0, "front on empty blob");   
    return data->front();
}

template <typename T>
inline T& Blob<T>::back() {
    check(0, "back on empty blob");   
    return data->back();
}

template <typename T>
inline const T & Blob<T>::front() const {
    check(0, "front on empty blob");   
    return data->front();
}

template <typename T>
inline const T & Blob<T>::back() const {
    check(0, "back on empty blob");   
    return data->back();
}

template <typename T>
inline T& Blob<T>::operator[](size_type n) {
    //std::cout << "== debug ==\n" 
    //          << "int Blob::[], n is: " << n << "\b" << std::endl;
    check(n, "subscript out of range");   
    return (*data)[n];
}

template <typename T>
inline const T& Blob<T>::operator[](size_type n) const {
    check(n, "subscript out of range");   
    return (*data)[n];
}


// -----------------------------------------------------------------------------
//
//      template BlobPtr
//      
// -----------------------------------------------------------------------------

template <typename T> bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator>(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator<=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator>=(const BlobPtr<T> &, const BlobPtr<T> &);


template <typename T>
class BlobPtr {
    friend bool operator== <T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator!= <T>(const BlobPtr<T> &, const BlobPtr<T> &);

    friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator> <T>(const BlobPtr<T> &, const BlobPtr<T> &);
    
    friend bool operator<= <T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator>= <T>(const BlobPtr<T> &, const BlobPtr<T> &);

public:
    typedef typename std::vector<T>::size_type size_type;
    
    BlobPtr() : curr(0) {} 
    
    BlobPtr(Blob<T> &a, size_type sz= 0) : wptr(&(a.data)), curr(sz) {}

    T& operator*() const;
    T* operator->() const;

    BlobPtr & operator++();
    BlobPtr & operator--();
    BlobPtr  operator++(int);
    BlobPtr  operator--(int);

    BlobPtr & operator+=(size_t);
    BlobPtr & operator-=(size_t);
    BlobPtr  operator+(size_t) const;
    BlobPtr  operator-(size_t) const;
    
    T & operator[] (size_t n);
    const T & operator[] (size_t n) const;

private:
    SharedPtr<std::vector<T> > check(size_type, const std::string &) const;
    SharedPtr<std::vector<T> > * wptr;   
    size_type curr;
    
};

//-----------------------------------------------------------------------------
//      friend function 
//-----------------------------------------------------------------------------

template <typename T> 
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.curr == rhs.curr; 
}


template <typename T> 
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs); 
}

template <typename T> 
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.curr < rhs.curr; 
}

template <typename T> 
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.curr > rhs.curr; 
}

template <typename T> 
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.curr <= rhs.curr; 
}

template <typename T> 
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.curr >= rhs.curr; 
}


//-----------------------------------------------------------------------------
//      Template BlobPtr memberfunction  function 
//-----------------------------------------------------------------------------


template <typename T> 
inline T & BlobPtr<T>::operator*() const {
    auto p = check(curr, "defrence pass end");
    return (*p)[curr];
}

template <typename T> 
inline T * BlobPtr<T>::operator->() const {
    return &this->operator*();
}

template <typename T> 
inline BlobPtr<T> & BlobPtr<T>::operator++() {
    check(curr, "increment past end of Blob<T>Ptr");
    ++curr;
    return  *this;
}

template <typename T> 
inline BlobPtr<T> & BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrenment past begin of Blob<T>Ptr");
    return  *this;
}

template <typename T> 
inline BlobPtr<T>  BlobPtr<T>::operator++(int) {
    auto ret = *this;
    ++*this;
    return ret;
}

template <typename T> 
inline BlobPtr<T>  BlobPtr<T>::operator--(int) {
    auto ret = *this;
    --*this;
    return ret;
}

template <typename T> 
inline BlobPtr<T> & BlobPtr<T>::operator+=(size_t n) {
    curr += n;
    check(curr, "increment past end of Blob<T>Ptr");
    return  *this;
}

template <typename T> 
inline BlobPtr<T> & BlobPtr<T>::operator-=(size_t n) {
    curr -= n;
    check(curr, "decrenment past begin of Blob<T>Ptr");
    return  *this;
}

template <typename T> 
inline BlobPtr<T> BlobPtr<T>::operator+(size_t n) const {
    BlobPtr<T> ret = *this;
    ret += n;
    return  ret;
}

template <typename T> 
inline BlobPtr<T> BlobPtr<T>::operator-(size_t n) const {
    BlobPtr<T> ret = *this;
    ret -= n;
    return ret;
}

template <typename T>
inline SharedPtr<std::vector<T> > 
BlobPtr<T>::check(size_type i, const std::string &msg) const
{
    //auto ret = wptr.lock();
    //if (!ret) throw std::runtime_error("unbound Blob<T>Ptr");
    //if (i >= ret->size()) throw std::out_of_range(msg);
    //return ret;
    
    auto ret = wptr->get();
    if (!ret) throw std::runtime_error("unbound Blob<T>Ptr");

    // Fixed 2.a: size access error, using (*wptr)->size() instead of 
    //  wptr->use_count()
    if (i > (*wptr)->size()) throw std::out_of_range(msg);
        return *wptr;
     
}

template <typename T>
inline T & BlobPtr<T>::operator[] (size_t n) {
  auto p = check(n, "deference out of range");  
  return (*p)[n];
}

template <typename T>
inline const T & BlobPtr<T>::operator[] (size_t n) const {
  auto p = check(n, "deference out of range");  
  return (*p)[n];
}



// -----------------------------------------------------------------------------
//
//      template ConstBlobPtr
//      
// -----------------------------------------------------------------------------

template <typename T> 
bool operator==(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
bool operator!=(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
bool operator<(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
bool operator>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
bool operator<=(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
bool operator>=(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);


template <typename T>
class ConstBlobPtr {
    friend bool operator== <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    friend bool operator!= <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

    friend bool operator< <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    friend bool operator> <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    
    friend bool operator<= <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    friend bool operator>= <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

public:
    typedef typename std::vector<T>::size_type size_type;
    
    ConstBlobPtr() : curr(0) {} 
    // Fixed 1: bug- can not initialize pionter wptr, type can not match.
    //  declare wptr as const type *const to fix it. 
    ConstBlobPtr(const Blob<T> &a, size_type sz= 0) : wptr(&(a.data)), curr(sz) {}

    const T& operator*() const;
    const T* operator->() const;

    ConstBlobPtr & operator++();
    ConstBlobPtr & operator--();
    ConstBlobPtr  operator++(int);
    ConstBlobPtr  operator--(int);

    ConstBlobPtr & operator+=(size_t);
    ConstBlobPtr & operator-=(size_t);
    ConstBlobPtr  operator+(size_t) const;
    ConstBlobPtr  operator-(size_t) const;
    
    const T & operator[] (size_t n) const;

private:
    const SharedPtr<std::vector<T> > check(size_type, const std::string &) const;
    
    const SharedPtr<std::vector<T> >* const  wptr;   
    size_type curr;
    
};

//-----------------------------------------------------------------------------
//      friend function 
//-----------------------------------------------------------------------------

template <typename T> 
bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
    return lhs.curr == rhs.curr; 
}


template <typename T> 
bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
    return !(lhs == rhs); 
}

template <typename T> 
bool operator<(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
    return lhs.curr < rhs.curr; 
}

template <typename T> 
bool operator>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
    return lhs.curr > rhs.curr; 
}

template <typename T> 
bool operator<=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
    return lhs.curr <= rhs.curr; 
}

template <typename T> 
bool operator>=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs) {
    return lhs.curr >= rhs.curr; 
}


//-----------------------------------------------------------------------------
//      Template ConstBlobPtr memberfunction  function 
//-----------------------------------------------------------------------------


template <typename T> 
inline const T & ConstBlobPtr<T>::operator*() const {
    auto p = check(curr, "defrence pass end");
    return (*p)[curr];
}

template <typename T> 
inline const T * ConstBlobPtr<T>::operator->() const {
    return &this->operator*();
}


template <typename T> 
inline ConstBlobPtr<T> & ConstBlobPtr<T>::operator++() {
    check(curr, "increment past end of Blob<T>Ptr");
     
    ++curr;
    return  *this;
}

template <typename T> 
inline ConstBlobPtr<T> & ConstBlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrenment past begin of Blob<T>Ptr");
    return  *this;
}

template <typename T> 
inline ConstBlobPtr<T>  ConstBlobPtr<T>::operator++(int) {
    auto ret = *this;
    ++*this;
    return ret;
}

template <typename T> 
inline ConstBlobPtr<T>  ConstBlobPtr<T>::operator--(int) {
    auto ret = *this;
    --*this;
    return ret;
}

template <typename T> 
inline ConstBlobPtr<T> & ConstBlobPtr<T>::operator+=(size_t n) {
    curr += n;
    check(curr, "increment past end of Blob<T>Ptr");
    return  *this;
}

template <typename T> 
inline ConstBlobPtr<T> & ConstBlobPtr<T>::operator-=(size_t n) {
    curr -= n;
    check(curr, "decrenment past begin of Blob<T>Ptr");
    return  *this;
}

template <typename T> 
inline ConstBlobPtr<T> ConstBlobPtr<T>::operator+(size_t n) const {
    ConstBlobPtr<T> ret = *this;
    ret += n;
    return  ret;
}

template <typename T> 
inline ConstBlobPtr<T> ConstBlobPtr<T>::operator-(size_t n) const {
    ConstBlobPtr<T> ret = *this;
    ret -= n;
    return ret;
}

template <typename T>
inline const SharedPtr<std::vector<T> > 
ConstBlobPtr<T>::check(size_type i, const std::string &msg) const
{
    auto ret = wptr->get();
    if (!ret) throw std::runtime_error("unbound Blob<T>Ptr");
   
    // Fixed 2.b: size access error, using (*wptr)->size() instead of 
    //  wptr->use_count()
    if (i >= (*wptr)->size()) throw std::out_of_range(msg);
        return *wptr;
}


template <typename T>
inline const T & ConstBlobPtr<T>::operator[] (size_t n) const {
  //std::cout << "== debug == \n" 
  //          << "in ConstBlobPtr[], n is: " << n 
  //          <<" size wptr is: " << (*wptr)->size() << "\n" << std::endl; 
  auto p = check(n, "deference out of range");  
  return (*p)[n];
}


#endif

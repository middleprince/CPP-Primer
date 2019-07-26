#ifndef ex16_21_stdBlob_h
#define ex16_21_stdBlob_h

#include <vector>
#include <string>
#include <iostream>
#include <memory>

template <typename> class StrBlob;
template <typename> class Blob;
template <typename T> 
bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T> 
class Blob {
    friend class StrBlob<T>;
    friend bool operator==(const Blob<T> &, const Blob<T> &);
public:
    typedef T vaule_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob() : data(std::make_shared<std::vector<T> >()) {}
    Blob(std::initializer_list<T>);
    
    size_type size() {return data->size(); }
    bool empty() {return data->empty(); }
    void push_back(const T &t) {data->push_back(t); }
    void push_back(const T &&t) {data->push_back(std::move(t)); }
    void pop_back();

    StrBlob<T> & begin();
    StrBlob<T> & end();


    T& back();
    T& operator[] (size_type i);
private:
    std::shared_ptr<std::vector<T> > data;
    void check(size_type, const std::string &) const;
};


template <typename T>
Blob<T>::Blob(std::initializer_list<T> il)
   : data(std::make_shared<std::vector<T> >(il)) {} 

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) 
        throw std::out_of_range(msg);
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "back on empty blob");   
    data->pop_back();
}

template <typename T>
StrBlob<T> & Blob<T>::begin() {
    check(0, "back on empty blob");   
    StrBlob<T> ret(this, 0);
    return ret;
}

template <typename T>
StrBlob<T> & Blob<T>::end() {
    StrBlob<T> ret(this, this->size()+1);
    return ret;
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty blob");   
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");   
    return (*data)[i];
}

// -----------------------------------------------------------------------------
//      template strBlob
// -----------------------------------------------------------------------------

template <typename T>
class BlobPtr {
public:
    typedef typename std::vector<T>::size_type size_type;
    BlobPtr() : curr(0) {} 
    BlobPtr(Blob<T> &a, size_type sz= 0) : 
        wptr(a.data), curr(sz) {}

    T& operator*() const;

    BlobPtr & operator++();
    BlobPtr & operator--();
    BlobPtr  operator++(int);
    BlobPtr  operator--(int);

    

private:
    std::shared_ptr<std::vector<T> > check(size_type, const std::string &) const;
    std::weak_ptr<std::vector<T> > wptr;   
    size_type curr;
    
};

template <typename T> 
std::shared_ptr<std::vector<T> > 
BlobPtr<T>::check(size_type i, const std::string &msg) const {
    auto ret = wptr.lock();
   if (!ret) 
       throw std::runtime_error("unbount BlobPtr");
   if (i >= ret->data.size())
       throw std::out_of_range(msg);
   return ret;

}

template <typename T> 
inline T & BlobPtr<T>::operator*() const {
    auto p = check(curr, "defrence pass end");
    return (*p)[curr];
}


template <typename T> 
inline BlobPtr<T> & BlobPtr<T>::operator++() {
    check(curr + 1, "pass end of block");
    curr += 1;
    return  *this;
}

template <typename T> 
inline BlobPtr<T> & BlobPtr<T>::operator--() {
    check(curr - 1, "ahead of begin");
    curr -= 1;
    return  *this;
}

template <typename T> 
inline BlobPtr<T>  BlobPtr<T>::operator++(int) {
    auto ret = *this;
    check(curr + 1, "pass end of block");
    curr += 1;
    return ret;
}

template <typename T> 
inline BlobPtr<T>  BlobPtr<T>::operator--(int) {
    auto ret = *this;
    check(curr - 1, "ahead of begin");
    curr -= 1;
    return ret;
}


// -----------------------------------------------------------------------------
//          tool function 
// -----------------------------------------------------------------------------
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    if (lhs.data.size() != rhs.data.size())    
        return false;
    bool wq = false;
    for_each(lhs.data.cbegin(), rhs.data.cend(), 
            [&wq](const T &a, const T &b) { 
                wq = a == b;
                if (!wq) return; 
            });
            
    return wq;
}

#endif

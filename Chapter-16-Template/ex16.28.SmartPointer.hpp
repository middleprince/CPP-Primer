#ifndef ex16_28_SmartPointer_hpp
#define ex16_28_SmartPointer_hpp
#include <iostream>

//------------------------------------------------------------------------------
//         class SharedPtr 
//------------------------------------------------------------------------------

template <typename T>
class SharedPtr {
    using DelFunc = void (*)(T*);
public:
    SharedPtr(T* ptr = nullptr, DelFunc del = nullptr) 
        : _ptr(ptr), _del(del), pcount(new size_t(ptr != nullptr)) { }
    ~SharedPtr();

    SharedPtr(const SharedPtr&);
    SharedPtr(const SharedPtr&&) noexcept;
    SharedPtr & operator=(SharedPtr); 

    void reset(T* ptr = nullptr, DelFunc del = nullptr) noexcept; 
    void swap(SharedPtr&) noexcept;
    
    T* get() const noexcept {return _ptr;}
    T& operator*() const noexcept {return *get();}
    T* operator->() const noexcept{return get();}
    size_t use_count() const noexcept {return *pcount;}
    explicit operator bool() {return _ptr != nullptr;}

private:
    T* _ptr = nullptr;
    size_t* pcount = nullptr;
    DelFunc _del = nullptr;
};

//------------------------------------------------------------------------------
//          Class SharedPtr member function
//------------------------------------------------------------------------------

template <typename T>
inline SharedPtr<T>::SharedPtr(const SharedPtr& lhs) 
    : _ptr(lhs._ptr), pcount(lhs.pcount), _del(lhs._del) {
        ++*pcount;
}

template <typename T>
inline SharedPtr<T>::SharedPtr(const SharedPtr&& rhs) noexcept : SharedPtr() {
    swap(rhs);
}

template <typename T>
inline SharedPtr<T>::~SharedPtr() {
    if (!_ptr)
        return;
    if (--*pcount == 0) {
        _del ? _del(_ptr) : delete _ptr; 
        delete pcount;
    }
    _ptr = nullptr;
    pcount = nullptr;
}

template <typename T>
inline SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr sp) {
    swap(sp);
    return *this;
}

template <typename T>
inline void SharedPtr<T>::reset(T* ptr, DelFunc del) noexcept {
    // safe and simple way to release memory using temp's destructor;
    SharedPtr temp(ptr, del);
    swap(temp);
}

template <typename T>
inline void SharedPtr<T>::swap(SharedPtr& lhs) noexcept {
    using std::swap;
    swap(_ptr, lhs._ptr);
    swap(pcount, lhs.pcount);
    swap(_del, lhs._del);
}



//------------------------------------------------------------------------------
//          Class UniquePtr
//------------------------------------------------------------------------------

// callable object
class Delete {
public:
    template <typename T> void operator() (T* ptr) const {delete ptr;}
};

template <typename T, typename D = Delete>
class UniquePtr {
public:
    UniquePtr(T* ptr = nullptr, const D& del = D()) noexcept 
        : _ptr(ptr), _del(del) {}
    ~UniquePtr() {_del(_ptr);}

    // declare them only not define to avoid copy
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr & operator=(const UniquePtr&) = delete; 

    UniquePtr(UniquePtr&&) noexcept;
    UniquePtr&  operator=(UniquePtr&&) noexcept;
    UniquePtr&  operator=(std::nullptr_t) noexcept;

    void reset(T* p = nullptr) noexcept; 
    T* release() noexcept; 
    void swap(UniquePtr&) noexcept;
    
    T* get() const noexcept {return _ptr;}
    D& getDeleter() noexcept {return _del;}
    const D& getDeleter() const noexcept {return _del;}
    T& operator*() const noexcept {return *_ptr;}
    T* operator->() const noexcept{return _ptr;}
    explicit operator bool() {return _ptr != nullptr;}
    T& operator[](size_t n) const {return _ptr[n];}

private:
    T* _ptr = nullptr;
    D _del;
};




template <typename T, typename D>
inline UniquePtr<T, D>::UniquePtr(UniquePtr&& rhs) noexcept 
    : _ptr(rhs._ptr), _del(std::move(rhs._del)) {
        rhs._ptr = nullptr;
    }

template <typename T, typename D>
inline UniquePtr<T, D>& UniquePtr<T, D>::operator=(UniquePtr &&rhs) noexcept {
    if (this != &rhs) {
        reset(); 
        _ptr = rhs._ptr;
        _del = std::move(rhs._del);
        rhs._del = nullptr;
    }
    return *this;
}
template <typename T, typename D>
inline UniquePtr<T, D>& UniquePtr<T, D>::operator=(std::nullptr_t ) noexcept {
    reset();
    
}
 
template <typename T, typename D>
inline void UniquePtr<T, D>::reset(T* p) noexcept {
    //UniquePtr temp(p);
    //swap(temp);
    _del(p);
    _ptr = p;
}

template <typename T, typename D>
inline T* UniquePtr<T, D>::release() noexcept {
    T *ret = _ptr; 
    _ptr = nullptr;
    return ret; 
}
template <typename T, typename D>
inline void UniquePtr<T, D>::swap(UniquePtr& lhs) noexcept {
    using std::swap;
    swap(_ptr, lhs._ptr);
    swap(_del, lhs._del);
}
#endif

//
//  ex13.5vecstr.hpp
//  Exercise 13.39 13.40 13.42
//
//
//  Write your own version of StrVec, including versions of
//  reserve, capacity (9.4, p. 356), and resize (9.3.5, p. 352).
//
//  Add constructor which can accept initializer_lis<string> parameters
//  Add operator[] for StrVec
//
//  using StrVec for TextQuery
//

#ifndef ex14_26_StrVec_h
#define ex14_26_StrVec_h

#include <memory>
#include <string>
#include <iostream>

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);
public:
    StrVec() : 
        elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(std::initializer_list<std::string>);

    StrVec(const StrVec &);
    StrVec & operator=(const StrVec &);
    ~StrVec();

    std::string& operator[](std::size_t);
    const std::string& operator[](std::size_t) const;

    void push_back(const std::string&);
    void pop_back();
    size_t size() const {return  first_free - elements;}
    size_t capacity() const {return cap - first_free;}
    std::string *begin() const {return elements;}
    std::string *end() const {return first_free;}
    
    void resize(size_t n);
    void reserve(size_t n);


private:
    std::allocator<std::string> alloc; // have to defined as no-static;
    std::string *elements;
    std::string *first_free;
    std::string *cap;

    void chk_n_alloc() {
        if (size() == capacity()) 
            reallocate();
    }

    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);

    void alloc_n_block(size_t );
    void initialize_range(const std::string*, const std::string*);

    void free();
    void reallocate();
    void resize(size_t n, const std::string&); 

};


StrVec::StrVec(std::initializer_list<std::string> il) {
    initialize_range(il.begin(), il.end());
}

StrVec::StrVec(const StrVec& old) {
    auto newdata = alloc_n_copy(old.begin(), old.end());
    elements = newdata.first;
    cap = first_free = newdata.second;
}

StrVec & StrVec::operator=(const StrVec &rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();

    elements = newdata.first;
    cap = first_free = newdata.second;

    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::pop_back() {
    if(first_free) {
        alloc.destroy(--first_free); 
    }

}



// tool function alloc_n_copy
// allocation new memory and copy old infomation into newly allocated memory;
std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto newdata = alloc.allocate(e-b);
    return {newdata, std::uninitialized_copy(b, e, newdata)};
}

// tool function: initializer_rage()
// for constrctor initialize_list
void StrVec::initialize_range(const std::string *b, const std::string *e) {
    auto newdata = alloc_n_copy(b, e);
    elements = newdata.first;
    cap = first_free = newdata.second;
}

// tool finction: free()
// clear the allocated memory
void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; ) 
            alloc.destroy(--p);
      
        // for_each() ambda version 
        //for_each(first_free, elements, 
        //        [](std::string &rhs) {alloc.destroy(&rhs); }
        
        alloc.deallocate(elements, cap - elements);
    }
}

// tool function: alloc_n_block()
// for reallocate function, to allocte n block momeries and copy the old data 
// into newly allocated data using move constructor!!
void StrVec::alloc_n_block(size_t n) {
    auto newdata = alloc.allocate(n);
    // recorde the old position for later updating
    auto dest = newdata;
    auto ele = elements;

    // using string move constructor to improving the performance.
    // which prevent copy old string data to the new position.
    for (size_t i = 0; i != size(); ++i) 
        alloc.construct(dest++, std::move(*ele++));

    free();
    elements = newdata;
    first_free = dest;
    cap = elements + n;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_block(newcapacity);
}


// tool function: resize
// true resize function for resize the constructed memory
void StrVec::resize(size_t n, const std::string &s) {
    if (n < size()) {
        while (first_free != elements + n) 
            alloc.destroy(--first_free);
    }
    if (n > size()) {
        if (n > capacity()) 
            resize(n * 2);
        for (auto i = size(); i != n; ++i)
            alloc.construct(first_free++, s);
    }
}

void StrVec::resize(size_t n) {
    resize(n, std::string());
}

void StrVec::reserve(size_t n) {
    if (n <= capacity())
        return ;
    alloc_n_block(n);
}

// overload == for StrVec
bool operator==(const StrVec &lhs, const StrVec &rhs) {
    if (lhs.size() != rhs.size())
        return false;
    auto l_bg = lhs.begin(), l_end = lhs.end();
    auto r_bg = rhs.begin(), r_end = rhs.end();
    
    while (l_bg != l_end && r_bg != r_end) {
        if (*l_bg++ == *r_bg++) {
            //std::cout << "# Debug # " << *l_bg << " " << *r_bg << std::endl;    
            continue; 
        }
        else
            return false;
    }
    return true;
}

// overload != for StrVec
bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

// overload < for StrVec
bool operator<(const StrVec &lhs, const StrVec &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

// overload >= for StrVec
bool operator>=(const StrVec &lhs, const StrVec &rhs) {
   return !(lhs < rhs); 
}

// overload > for StrVec
bool operator>(const StrVec &lhs, const StrVec &rhs) {
   return rhs < lhs; 
}


// overload <= for StrVec
bool operator<=(const StrVec &lhs, const StrVec &rhs) {
   return !(lhs > rhs); 
}

// overload for operator[]
std::string& StrVec::operator[](std::size_t n) {
    return elements[n];    
}

// overload for operator[] const version
const std::string& StrVec::operator[](std::size_t n) const {
    return elements[n];    
}
#endif

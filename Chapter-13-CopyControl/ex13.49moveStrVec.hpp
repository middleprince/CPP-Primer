//
//  ex13.5vecstr.hpp
//  Exercise 13.39 13.40 13.42
//
//
//  Write your own version of StrVec, including versions of
//  reserve, capacity (9.4, p. 356), and resize (9.3.5, p. 352).
//
//  Add constructor which can accept initializer_lis<string> parameters
//
//  using StrVec for TextQuery
//

#ifndef ex13_5strvec_h
#define ex13_5strvec_h

#include <memory>
#include <string>

class StrVec {
public:
    StrVec() : 
        elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(std::initializer_list<std::string>);

    StrVec(const StrVec &);
    StrVec & operator=(const StrVec &);
    ~StrVec();

    // add move constructor and move assign constructor
    StrVec(StrVec &&) noexcept;
    StrVec &operator=(StrVec &&) noexcept;

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

// StrVec move constructor
StrVec::StrVec(StrVec &&old) noexcept : elements(std::move(old.elements)), 
    first_free(std::move(old.first_free)), cap(std::move(old.cap)) {
        old.elements = old.cap = old.first_free = nullptr;
     
}

// StrVec move assign constructor
StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free(); 
        elements = rhs.elements;   
        first_free = rhs.first_free;
        cap = rhs.cap;

        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
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






#endif

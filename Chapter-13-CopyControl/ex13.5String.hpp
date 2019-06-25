#ifndef ex13_5String_h
#define ex13_5String_h

#include <memory>
#include <algorithm>
#include <iostream>


class String {
public:
    String() : String("") {}
    String(const char *);
    String(const String&);
    String & operator=(const String&);
    ~String();

    const char* c_str() {return elements; }
    size_t size() {return end - elements;}
    size_t lenght() {return end - elements -1; }

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;

    std::pair<char*, char*> alloc_n_copy(const char *, const char *);
    void free();
    void initialize_range(const char *, const char *);
};

String::String(const char *s) {
    char *sl = const_cast<char*>(s);
    while(*sl) 
        ++sl;
    initialize_range(s, ++sl);
    std::cout << "String() called for copy construct" << std::endl;
}

String::String(const String &old) {
    initialize_range(old.elements, old.end);

}

String & String::operator=(const String &rhs) {
    auto newdata = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newdata.first;
    end = newdata.second; 
    std::cout << " = copy assign constructor called" << std::endl;

    return *this;

}

String::~String() {
    free();
}

std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e) {
    auto datanew = alloc.allocate(e - b); 
    return {datanew, std::uninitialized_copy(b, e, datanew) };
}

void String::initialize_range(const char *first, const char *last) {
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    end = newdata.second;
}

void String::free() {
   if(elements) {
       std::for_each(elements, end, [this](char &c) { alloc.destroy(&c); }); 
       alloc.deallocate(elements, end - elements);
        
   } 

}
#endif



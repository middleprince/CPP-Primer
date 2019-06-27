// Add opreator == and != 
#ifndef ex14_16_Stringpp_h
#define ex14_16_Stringpp_h

#include <memory>
#include <algorithm>
#include <iostream>


class String {
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);
public:
    String() : String("") {}
    String(const char *);
    String(const String&);
    String & operator=(const String&);
    ~String();

    const char* c_str() const {return elements; }
    size_t size() const {return end - elements;}
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

// output string operator << for String
std::ostream& operator<<(std::ostream &os, const String &item) {
    auto bg = item.c_str();
    while(*bg)
        os << *bg++;
    return os;
}

// overload ==
bool operator==(const String &lhs, const String &rhs) {
    if (lhs.size() != rhs.size())
        return false;

    char *lb = lhs.elements, *le = lhs.end;
    char *rb = rhs.elements, *re = rhs.end;
    
        while(lb != le && rb != re) {
        if (*lb++ == *rb++)
            continue;
        else
            return false;
    }
    
    return true;
}

// overload != 
bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs==rhs);
}
#endif



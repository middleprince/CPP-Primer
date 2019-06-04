#include <iostream>
#include <string>
using namespace std;

class base {
public:
    string name() {return basename;}
    virtual void print(ostream &os) { os << basename;}
    // virtual distructor is needed
    virtual ~base() = default;
    
private:
    string basename;
};

class derived : public base {
public:
    void print(ostream &os) { 
        // can't not call self
        // print(os);
        os << " " << i;
    }
private:
    int i;
};



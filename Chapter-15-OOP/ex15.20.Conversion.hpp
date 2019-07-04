/*
=================================================================================
C++ Primer 5th Exercise Answer Source Code

ex15.20  about inherientaton converting to base class and accessbility.


Base,
Pub_Derv, Priv_Derv, Prot_Derv
Derived_from_Public, Derived_from_Private, Derived_from_Protected
*/

#ifndef ex15_20_Conversion_h
#define ex15_20_Conversion_h

class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    int priv_mem;
};

struct Pub_Dev : public Base {
    int f() const {
        return prot_mem;
    }

    void memfcn(Base &b) {
        b = *this; 
    }

};

struct Prot_Dev : protected Base {
    int f() const {
        return prot_mem; 
    }
    
    void memfcn(Base &b) {
        b = *this; 
    }
};

struct Priv_Dev : private Base {
    int f() const {
        return prot_mem; 
    }
    
    void memfcn(Base &b) {
        b = *this; 
    }
};

struct Deriv_from_Public : public Pub_Dev {
    int use_base() {
        return prot_mem; 
    } 
    
    void memfcn(Base &b) {
        b = *this; 
    }
};

struct Deriv_from_Protect : public Prot_Dev {
    int use_base() {
        return prot_mem; 
    } 
    
    void memfcn(Base &b) {
        b = *this; 
    }
};

struct Deriv_from_Private : public Priv_Dev {

    // cannot cast 'Deriv_from_Private' to its private base struct 'Base'
    //int use_base() { return prot_mem; } 
    
    // cannot cast 'Deriv_from_Private' to its private base struct 'Base'
    //void memfcn(Base &b) { b = *this; }
};

#endif


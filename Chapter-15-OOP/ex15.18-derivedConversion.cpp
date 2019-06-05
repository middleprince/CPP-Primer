/**
 *
 * Exercise about accessibility  of devried class convered to base class.
 *
 */


/**
 *
 * Accessibility of Derived-to-Base Conversion
 *  Assuming D inherits B
 *
 * 1. User code may use the derived-to-base conversion only if D inherits 
 *    publicly from B. User code may not uset the converdion if D inherits
 *    from B using either protected or provate.
 *
 * 2. Member function and friends of D can use the conversion to B regardless 
 *    of how D inheris form B.The derived-to-base conversion to direct base class
 *    is always accessible to friends of a derived class.
 *
 * 3. Member functions and friends of class derived from D may use the derived-
 *    -to-base conversion if D inherits from B using either public or ptotected.
 *    Such code may not use the convrsion if D inherits privately from B. 
 *
 *
 *
 *
 *
 *
 *
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Base {
protected:
    int prot_mem;

};

class Sneaky : public Base {
    friend void clobber(Sneaky&); 
    friend void clobber(Base&);
    int j;
};
void clobber(Sneaky &s) {
    s.j = s.prot_mem = 0;
}

//  In devried class ,the protected member in base class can only be accessed
//  by obj of devried class  member of friend function in derived class.
// 
// can not access prot_mem by using base class, instead using derived class 
// will do fine. 
//void clobber(Base &b) {
//    b.prot_mem = 0;
//}
//


class Base2 {
public:
    Base2() = default;
    Base2(int i, char c) : prot_mem(i), priv_mem(c) {}
    void pub_mem();
    void memfcn(Base2 &b) { b = *this;}
protected: 
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base2 {
    Pub_Derv() = default;
    Pub_Derv(int i, char c) : Base2(i, c) {}
    int f() {
        cout << "This is Pub_Derv" << endl; 
        return prot_mem; 
    }

    // In member function or friends of devied th class: the derived class 
    // always can use the convrsion to direct  class regardless how devied 
    // class inherited from base. 
    void memfcn(Base2 &b) { b = *this;}
    
    // can not access priv_mem for it's a private member of base2 
    //char g(){return priv_mem; }
};

struct Priv_Derv : private Base2 {
    // the private lable in devied list can do no influence on protected member
    Priv_Derv() = default;
    Priv_Derv(int i, char c) : Base2(i, c) {}
    
    int f1()  const {
       cout << "This is Priv_Derv" << endl;
       return prot_mem;
    }
   
    // accordin to rule 2 
    void memfcn(Base2 &b) { b = *this;}
};

struct Prot_Derv : protected  Base2 {
    Prot_Derv() = default;
    Prot_Derv(int i, char c) : Base2(i, c) {}
    
    int f2() {
        cout << "This is Prot_Derv " << endl; 
        return prot_mem;
    }
    //friend void fFunc();
    
    // according to rule 2
    void memfcn(Base2 &b) { b = *this;}
};

void Base2::pub_mem() {
    cout << "the data prot_mem in Base2 are:" << prot_mem << endl;
}

//void fFunc() {
//   cout << "protected member prot_mem is: " << pub_mem() << endl;
//}

struct Derived_from_Public : public Pub_Derv {
    Derived_from_Public() = default;
    Derived_from_Public(int i, char c) : Pub_Derv(i, c) {}
    int use_base() {
        cout << "This is Derived_from_Public" << endl; 
        return prot_mem;
    }
    
    // According to rule3, Derived_from_Public is public to public
    void memfcn(Base2 &b) { b = *this;}
};

struct Derived_from_Private : public Priv_Derv {
    Derived_from_Private() = default;
    Derived_from_Private(int i, char c) : Priv_Derv(i, c) {}
    
    int use_base() {
        cout << "This is Derived_from_Private" << endl; 
        //return prot_mem;
        return 0;
    }
    
    
    //  According to rule2 , Derived_from_Private can not make the conversion
    //  becuase it is inherits from private subclass 
    //void memfcn(Base2 &b) { b = *this;}
};

struct Derived_from_Protect : public Prot_Derv {
    Derived_from_Protect() = default;
    Derived_from_Protect(int i, char c) : Prot_Derv(i, c) {}
    
    int use_base() {
        cout << "This is Derived_from_Protect" << endl; 
        return prot_mem;
    }
    
    // According to rule3  
    void memfcn(Base2 &b) { b = *this;}
};

int main() {
    Pub_Derv d1(10, 'A');
    Priv_Derv d2(20, 'B');
    Prot_Derv d3(30, 'C');
    Derived_from_Public dd1(40, 'D');
    Derived_from_Private dd2(50, 'E');
    Derived_from_Protect dd3(60, 'F');
    
    // pointer to Pub_Derv
    Base2 *p =  &d1; 
    
    cout << "#1 Test: Pointer to Pub_Derv\n";  
   
    // can not convert Private class to it's base
    //p = &d2;
    
    /** can only convert public inhirented derived class to it's base class
     * d3 in protected devied
     */ 
    //p = &d3;
    
    // dd1 is publicly devied
    p = &dd1;
   
    
    /** can only convert public inhirented derived class to it's base class
     * dd2 is private devied
     */ 
    //p = &dd2;


    /** can only convert public inhirented derived class to it's base class
     * dd3 is protected devied
     */ 
    //p = &dd3;

    return 0;
}

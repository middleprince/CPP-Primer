#include <iostream>
#include <string>
using namespace std;

class base {
public:
    base() = default;
    base(const string &in) : basename(in) {}
    string name() {return basename;}
    virtual void print(ostream &os) { os << basename << endl;}
    // virtual distructor is needed
    virtual ~base() = default;
    
private:
    string basename;
};

class derived : public base {
public:
    derived() = default;
    derived(int i_in) : i(i_in) {}
    void print(ostream &os) { 
        // can't not call self
        // print(os);
        os << " " << i << endl;
    }
private:
    int i;
};

int main() {
    base bobj("This is base");
    derived dobj(5);
    base *bp1 = &bobj;
    base *bp2 = &dobj;
    base &br1 = bobj;
    base &br2 = dobj;

    cout << "#1 obj print() test" << endl; 
    bobj.print(cout);
    dobj.print(cout);
   
    cout << "#2 ptr name() test" << endl; 
    cout << "bp1 name: " <<  bp1->name() << endl;
    cout << "bp2 name: " << bp2->name() << endl;
    
    cout << "#3 ref print() test" << endl; 
    br1.print(cout);
    br2.print(cout);

    return 0;
}



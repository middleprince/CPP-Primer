#include <memory>
#include <iostream>

using namespace std;

int main() {
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;

    //IntP p0(ix);
    //IntP p1(pi);
    IntP p2(pi2);
    cout << "p2's content is: " << *p2 << endl;
    
    // can not assign a internal poiter to uniquePtr 
    //IntP p3(&ix);
    
    IntP p4(new int(2018));
    
    // can not assign a internal poiter to uniquePtr 
    //IntP p5(p2.get());

}

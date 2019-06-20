#include <memory>
#include <iostream>
#include <vector>

using namespace std;

void process(shared_ptr<int> ptr) {
    cout << "In process, " << ptr << " using count is: " 
        << ptr.use_count() << " contents: " << *ptr << endl;
}

int main() {
    auto p = new int(2);
    auto sp = make_shared<int>(100); 
    shared_ptr<int> np(new int(200));

    cout << "Out process, " << sp << " using count is: " 
        << sp.use_count() << " contents: " << *sp << endl;
    process(sp);

    cout << "Out process, " << np << " using count is: " 
        << np.use_count() << " contents: " << *np << endl;
    process(shared_ptr<int>(np));
    
    //process(p);
    //process(new int());
    process(shared_ptr<int>(p));



}


#include <memory>
#include <iostream>

using namespace std;

int main() {
    unique_ptr<int> up(new int(100));
    unique_ptr<int> up2;

    // error msg: call to implicitly-deleted copy constructor of 'unique_ptr<int>'
    //unique_ptr<int> up3(up);
    
    //  error msg: cannot be assigned because its copy assignment operator is implicitly deleted 
    //up2 = up;
    

    //unique_ptr<int> up3(up);
}

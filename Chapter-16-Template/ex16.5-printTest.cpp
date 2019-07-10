#include "ex16.5.print.hpp"
#include <string>


int main() {
    int numArray[5]{1, 2, 3, 4, 5}; 
    std::string strArray[2]{"test", "string long"};

    print(numArray);
    cout << endl;
    print(strArray);
    return 0;

}

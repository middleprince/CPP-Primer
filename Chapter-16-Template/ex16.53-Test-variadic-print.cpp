#include "ex16.53.variadicPrint.hpp"

int main() {
    cout << "## test for one argument ##\n";
    print(cout, 12);
    cout << endl;

    cout << "## test for two argument ##\n";
    string s("two");
    double d = 3.14;
    print(cout, s, d);
    cout << endl;

    cout << "## test five two argument ##\n";
    s = "five:";
    d = 2.128; 
    int i = 5;
    char a = 'V';
    char strs[]("char strs array");
    
    print(cout, s, d, i, a, strs);
    cout << endl;


    return 0;
}

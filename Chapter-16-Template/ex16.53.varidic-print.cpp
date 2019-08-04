#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ostream;

template <typename T>
ostream & print(ostream &os, const T &t) {
    return os << t;
}

template <typename T, typename... Args>
ostream & print(ostream &os, const T& t, const Args&... rest) {
    os << t << " "; 
    return print(os, rest...);

}


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

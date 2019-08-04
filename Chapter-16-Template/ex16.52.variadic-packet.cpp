#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T, typename ... Args>
void foo(const T &t, const Args& ... rest) {
    cout << "frist argument is : " << t << endl;
    cout << "Arguments counts is : " << sizeof...(rest) << endl;
}

int main() {
    int i = 0;
    double d = 3.14;
    string s("hi i'm a string");
 
    cout << "## four arguments ##" << endl;
    foo(i, s, 42, d);
    
    cout << "## three arguments ##" << endl;
    foo(s, 42, "hi");

    cout << "## two arguments ##" << endl;
    foo(d, s);
    
    cout << "## one arguments ##" << endl;
    foo("one");
    
    return 0;
}


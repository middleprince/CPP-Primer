#include "ex16.48.debugRep.hpp"
int main() {

    string s("test for string");
    cout << "## for string(test for string)" << endl;
    cout << debugRep(s) << endl;

    cout << "## for string *s" << endl;
    cout << debugRep(&s) << endl;

    cout << "## for const string *s" << endl;
    const string *sp = &s;
    cout << debugRep(sp) << endl;

    cout << "## for const char *s" << endl;
    cout << debugRep("this is literal") << endl;
    
    char strs[]{"this is char[]"};
    cout << "## for char *s" << endl;
    cout << debugRep(strs) << endl;
    

    
}

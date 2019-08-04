#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

template <typename T>
string debugRep(const T &t) {
    ostringstream os;
    os << t;
    cout << "== debugRep(const T &t) == \n" << endl;
    return os.str();
}

template <typename T>
string debugRep(T &t) {
    ostringstream os;
    os << t;
    cout << "== debugRep(T &t) == \n" << endl;
    return os.str();
}

template <typename T>
string debugRep(T *p) {
    ostringstream os;
    os << "ponters param " << p;
    if (p)
        cout << "== debugRep(T *p) == \n" << debugRep(*p) << endl;
    else 
        cout << "null pointer\n";
    return os.str();
}

template <typename T>
string debugRep(const T *p) {
    ostringstream os;
    os << "ponters param " << p;
    if (p)
        cout << "== debugRep(const T *p) == \n" << debugRep(*p) << endl;
    else 
        cout << "null pointer\n";
    return os.str();
}

string debugRep(const string &s) {
    cout << "== debugRep(const string &s)== \n" << endl;
    return " " + s + " ";

}

string debugRep(string &s) {
    cout << "== debugRep(string &s)== \n" << endl;
    return " " + s + " ";

}

string debugRep(char *p) {
    cout << "== debugRep(char *p)==\n" << endl;
    return debugRep(string(p));
}
string debugRep(const char *p) {
    cout << "== debugRep(const char *p)==\n" << endl;
    return debugRep(string(p));
}
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

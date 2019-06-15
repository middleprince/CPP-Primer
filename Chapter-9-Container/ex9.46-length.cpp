#include <iostream>
#include <string>

using namespace std;

string  addPreSufix(const string &name, const string& prefix, const string &sufix) {
    string temp = name;
    string::size_type t = 0;
    temp.insert(t, prefix);
    temp.insert(temp.size(), sufix);

    return temp;
}

int main() {
    string name{"Young HU"};
    string prefix{"Dr."};
    string sufix{"Jr."};

    cout << "#Test after insertation name is showing below \n";
    cout << addPreSufix(name, prefix, sufix) << endl;
    
    return 0;
}

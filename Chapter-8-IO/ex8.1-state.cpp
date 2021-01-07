/*
 * exercise about io stream state
 */

#include <iostream>
#include <string>
using namespace std;

istream &inToOut(istream &in) {
    string line;
    while(getline(in, line)) {
        cout << line << endl; 
        cout << in.rdstate() << endl;
    }
    cout << in.rdstate() << endl;
    in.clear();
    return in;
}

int main() {
    inToOut(cin);
    return 0;
}

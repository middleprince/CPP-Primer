/*
 * exercise about io stream state
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

istream &inToOut(istringstream &in) {
    string line;
    while(getline(in, line)) {
        cout << line << endl; 
    }
    in.clear();
    return in;
}

int main() {
    istringstream strs("The test");
    inToOut(strs);
    return 0;
}

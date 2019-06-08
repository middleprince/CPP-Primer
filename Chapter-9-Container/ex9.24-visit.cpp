#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    cout << "#Test1: \n";
    
    //cout << "at: " << a.at(0) << endl;
    cout << "subscript: " << a[0] << endl;
    cout << "front: " << a.front() << endl;
    cout << "begin:: " << *a.begin() << endl;
    a[0];
    return 0;
}



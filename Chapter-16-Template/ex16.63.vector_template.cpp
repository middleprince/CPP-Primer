#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
int ocurrCount(const std::vector<T> &vecT, T to_found) {
    int ret = 0;
    for (auto iter = std::find(vecT.begin(), vecT.cend(), to_found); 
            iter != vecT.cend(); iter = find(++iter, vecT.cend(), to_found)) {
        ++ret;    
        //std::cout << "debug in while find\nfound: " << *iter << std::endl;
    } 
    return ret;
}

//=============================================================================
//      Test for string, int and double vectors.
//=============================================================================
using std::cout;
using std::endl;
using std::string;
using std::vector;

void testInt() {
    vector<int> vecInt{1, 100, 203, 4, 23, 4}; 
    cout << "== test for int ==\n"; 
    if (2 == ocurrCount(vecInt, 4))
        cout << "PASS\n" << endl;
    else 
        cout << "FAIL\n" << endl;
}

void testDouble() {
    vector<double> vecDouble{1.2, 10.0, 20.3, 4.5, 2.3, 4.6, 20.3}; 
    cout << "== test for double ==\n"; 
    if (2 == ocurrCount(vecDouble, 20.3))
        cout << "PASS\n" << endl;
    else 
        cout << "FAIL\n" << endl;
}

void testString() {
    vector<string> vecString{"hello", "you", "and", "me", "so", "me"}; 
    cout << "== test for stirng ==\n"; 
    if (2 == ocurrCount(vecString, string("me")))
        cout << "PASS\n" << endl;
    else 
        cout << "FAIL\n" << endl;
}

int main() {
    testInt(); 
    testDouble();
    testString();
    return 0;

}



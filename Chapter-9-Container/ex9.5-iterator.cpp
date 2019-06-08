#include <iostream>
#include <vector>
using namespace std;

bool isIn(vector<int>::const_iterator va, vector<int>::const_iterator vb, int x) {

    for (; va != vb; ++va)
        if(*va == x)
            return true;
    return false;
}

int main() {
    vector<int> vs{1, 2, 3, 4, 5, 4};
    int x_in = 5;
    vector<int>::const_iterator vb = vs.begin();
    vector<int>::const_iterator ve = vs.end();
    cout << isIn(vb, ve, x_in)  << endl;   

}


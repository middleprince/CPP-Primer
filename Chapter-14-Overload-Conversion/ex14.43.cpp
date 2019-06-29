#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    vector<int> ivec{12, 4, 8};
    
    int num;
    cin >> num;

    modulus<int> mod;
    auto predictor = [&](int item) {return mod(item, num) == 0;};
    auto divideable = any_of(ivec.cbegin(), ivec.cend(), predictor);
    cout << (divideable ? "Yes" : "No") << endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> vec;
    vec.reserve(10);
    fill_n(back_inserter(vec), 10, 1);

    for (const auto &item : vec)
        cout << item << " ";
    cout << endl;

    return 0;

}

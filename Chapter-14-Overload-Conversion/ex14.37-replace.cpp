#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class IsEqual {
    int value;
public:
    IsEqual(int v) : value(v) {}
    bool operator() (int a) {return a == value;}
};

int main() {
    vector<int> nums{1, 2, 3, 43, 45, 2, 12, 31};
    
    cout << "before replace 2 contens is:" << endl;
    for (const auto &item : nums)
        cout << item << " ";
    cout << endl;

    std::replace_if(nums.begin(), nums.end(), IsEqual(2), 1111);
    cout << "# after replace 2 contens is:" << endl;
    for (const auto &item : nums)
        cout << item << " ";
    cout << endl;

    return 0;
}

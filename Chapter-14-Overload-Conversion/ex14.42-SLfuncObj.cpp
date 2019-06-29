#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;


int main() {
    vector<int> ivec{10, 30, 20, 1034}; 
    using placeholders::_1;
    
    auto count = count_if(ivec.cbegin(), ivec.cend(), bind(greater<int>(), _1, 1024));
    cout << "the numbers which count in total  greater than 1024 is: " << endl;
    cout << count << endl;

    vector<string> strvec{"pooh", "hello", "you", "pooh"};
    auto found = find_if(strvec.cbegin(), strvec.cend(), bind(not_equal_to<string>(), _1, "pooh"));
    cout << "the first word which is not \"pooh\" is: " << endl;
    cout << *found << endl;

    transform(ivec.begin(), ivec.end(), ivec.begin(), bind(multiplies<int>(), _1, 2));
    cout << "After multiplied by 2 showing: " << endl;
    for (const auto &item : ivec )
        cout << item << " ";
    cout << endl;
    
    return 0;
}


/*
 * @function: find the longest part of the words which don's have ascenders and descenders.
 */

#include <iostream>
#include <string>

using namespace std;

string findUnion(const string& strs) {
    string results;
    string target{"ybdfghjklpq"};
    //bool found = false;
    string::size_type t = 0;
    while (t < strs.size()) {
        auto index = strs.find_first_not_of(target, t); 
        if (index != string::npos) {
            results.push_back(strs[index]); 
            t = index + 1; 
        } else {
            results.push_back(' ');
            ++t;
        }
        //cout << "##Debug## t: " << t << endl;
    }
    return results;
}

int main() {

    string test_str{"never say you have identified this"};
    cout << "# Test for the function\n" << "Origin words is showing below: \n";
    cout << test_str << endl;
    cout << "The result is showing below\n";
    cout << findUnion(test_str) << endl;
    return 0;
}

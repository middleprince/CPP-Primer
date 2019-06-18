#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::placeholders;


void elimDups(vector<string> &strs) {
    auto index = unique(strs.begin(), strs.end());
    strs.erase(index, strs.end());
}

void printStringVec(const vector<string> &strs) {
    for (const auto &item : strs)
        cout << item << " "; 
    cout << endl;
}
bool isLonger(const string &item, string::size_type len) {
    return item.size() > len;
}

void biggies(vector<string> &strs, vector<string>::size_type len) {
    elimDups(strs);    

    stable_sort(strs.begin(), strs.end(), 
                [] (const string &a, const string &b) { return a.size() < b.size();});
    auto location = find_if(strs.begin(), strs.end(), 
            bind(isLonger, _1, len));
    
    for_each(location, strs.end(), [] (const string &item) {cout << item << " ";});
    cout << endl;

}

int main() {
    vector<string> strs;
    string words;
    while (cin >> words)
        strs.push_back(words);

    cout << "# input data are showing below\n";
    printStringVec(strs);
    cout << endl;

    cout << "# After biggies function, the data is showing below\n";
    biggies(strs, 5);
    
    return 0;
}

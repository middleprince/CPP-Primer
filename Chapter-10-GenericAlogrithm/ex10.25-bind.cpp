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

bool checkSize(const string &item, string::size_type len) {
    return item.size() < len;
}

void biggies(vector<string> &strs, vector<string>::size_type len) {
    elimDups(strs);    

    auto location = stable_partition(strs.begin(), strs.end(), bind(checkSize, _1, len));

    
    for_each(location+1, strs.end(), [] (const string &item) {cout << item << " ";});
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

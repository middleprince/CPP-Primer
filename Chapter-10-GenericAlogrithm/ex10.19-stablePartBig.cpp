#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


void elimDups(vector<string> &strs) {
    auto index = unique(strs.begin(), strs.end());
    strs.erase(index, strs.end());
}

void printStringVec(const vector<string> &strs) {
    for (const auto &item : strs)
        cout << item << " "; 
    cout << endl;
}

void biggies(vector<string> &strs, vector<string>::size_type len) {
    elimDups(strs);    

    auto location = stable_partition(strs.begin(), strs.end(), 
                            [len] (const string &item) {return item.size() <= len;});

    // output from the frist false item whose length is longer than len 
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

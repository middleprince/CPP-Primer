#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;


void elimDups(list<string> &strs) {
    unique(strs.begin(), strs.end());
}

void printStringVec(const list<string> &strs) {
    for (const auto &item : strs)
        cout << item << " "; 
    cout << endl;
}

void biggies(list<string> &strs, list<string>::size_type len) {
    elimDups(strs);    

    strs.sort( [] (const string &a, const string &b) { return a.size() < b.size();});
    auto location = find_if(strs.begin(), strs.end(), 
            [len](const string &item) { return item.size() >= len;});
    
    for_each(location, strs.end(), [] (const string &item) {cout << item << " ";});
    cout << endl;

}

int main() {
    list<string> strs;
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

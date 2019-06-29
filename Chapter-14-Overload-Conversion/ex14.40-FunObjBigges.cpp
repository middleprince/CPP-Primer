#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class StrCompare {
public:
    bool operator() (const string &a, const string &b) {
        return a.length() < b.length(); 
    }
};

class SizeComp {
    size_t len;
public:
    SizeComp(size_t n = 0) : len(n) {}
    bool operator() (const string &s) {
        return s.length() >= len; 
    }
};

class StrPrint {
public:
    void operator()(const string &s) {
        cout << s << " "; 
    }
};

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

    stable_sort(strs.begin(), strs.end(), StrCompare());
                
    auto location = find_if(strs.begin(), strs.end(), SizeComp(len));
            
    
    for_each(location, strs.end(), StrPrint()); 
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

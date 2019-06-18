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

long  biggies(vector<string> &strs, vector<string>::size_type len) {
    elimDups(strs);    

    stable_sort(strs.begin(), strs.end(), 
                [] (const string &a, const string &b) { return a.size() < b.size();});
    auto sizeWord = count_if(strs.begin(), strs.end(), 
            [len](const string &item) { return item.size() > len;});

    return sizeWord;    

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
    cout << "The numbers of words which size bigger than 5 is: " 
        << biggies(strs, 5);
    
    return 0;
}

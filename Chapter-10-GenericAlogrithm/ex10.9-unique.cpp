#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

void printString(const vector<string> &to_print) { 
    for (const auto &item : to_print)
        cout << item << " ";
    cout << endl;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    
    printString(words);

    auto end_unique = unique(words.begin(), words.end());
    
    printString(words);

    words.erase(end_unique, words.end());
    printString(words);
}
int main() {
    string strs;
    vector<string> strs_in;
    
    while (cin >> strs)
        strs_in.push_back(strs);

    printString(strs_in);
    elimDups(strs_in);
    return 0;
}

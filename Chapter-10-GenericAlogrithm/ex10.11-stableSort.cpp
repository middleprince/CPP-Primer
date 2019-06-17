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
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main() {
    string strs;
    vector<string> strs_in;
    
    while (cin >> strs)
        strs_in.push_back(strs);

    cout << "The original string is showing below: \n";
    printString(strs_in);
    cout << endl;

    elimDups(strs_in);
    cout << "After eliminating, strs is showing blow: \n";
    printString(strs_in);
    cout << endl;

    cout << "After stable srt:\n";
    stable_sort(strs_in.begin(), strs_in.end());
    printString(strs_in);
    cout << endl;

    return 0;
}

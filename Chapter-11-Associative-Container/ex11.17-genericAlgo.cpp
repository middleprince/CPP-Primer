#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int main() {
    multiset<string> mset; 
    vector<string> strs{"one", "two", "three"};
    vector<string> temp, temp2;

    copy(strs.begin(), strs.end(), inserter(mset, mset.end())); 
    for (const auto &item : mset)
        cout << item;
    cout <<endl;

    //copy(strs.begin(), strs.end(), back_inserter(mset)); 
    
    copy(mset.begin(), mset.end(), inserter(temp, temp.end())); 
    for (const auto &item : temp)
        cout << item;
    cout << endl;

    
    copy(mset.begin(), mset.end(), back_inserter(temp2));
    for (const auto &item : temp2)
        cout << item;
    cout << endl;

    
    return 0;        
}


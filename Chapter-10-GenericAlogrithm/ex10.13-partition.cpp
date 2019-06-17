#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printStringVec(const vector<string> &strs) {
    for (const auto &item : strs)
        cout << item << " ";
    cout << endl;

}

int main() {

    vector<string> strs;
    string temp;
    while(cin >> temp)
        strs.push_back(temp);

    cout << "The original strs is showing below:\n";
    printStringVec(strs);

    cout << "After Partition:\n";
    auto index = partition(strs.begin(), strs.end(), 
            [](const string& the_str) {return the_str.size() > 5; } ); 
    strs.erase(index, strs.end());
    printStringVec(strs); 
    
   return 0; 

}

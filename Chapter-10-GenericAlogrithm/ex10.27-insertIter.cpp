#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <list>

using namespace std;
    
int main() {
    vector<string> strs;
    list<string> results;
    string temp;
    while (cin >> temp)
        strs.push_back(temp);

    unique_copy(strs.begin(), strs.end(), front_inserter(results));

    cout << "#The results is showing below:\n";
    for (const auto &item : results)
        cout << item << " ";

    cout << endl;

    return 0;
}

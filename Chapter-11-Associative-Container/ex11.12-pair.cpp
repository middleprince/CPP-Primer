#include <utility>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void printPair(const pair<string, int> &the_pair) {
    cout << the_pair.first << " " << the_pair.second << endl;
}

int main() {
    string word;
    int num;
    vector<pair<string, int>> pair_container;
    
    pair<string, int> temp;
    
    while (cin >> word >> num)  {
        temp = make_pair(word, num); 
        pair_container.push_back(temp);
    }

    for (const auto &item : pair_container)
        printPair(item);
    cout << endl;

    return 0;
}


#include <map>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;



void printMap(const multimap<string, string> &map_value) {
    for (const auto &item : map_value)
        cout << "Autor is: " << item.first << "| book name: " << item.second << endl;
    
}



int main() {
    unordered_map<string, size_t> words;
    set<string> excludes{"The", "But", "And", "Or", "A", "An", "The", "but", "and", "or", "an", "a"};      
    string word;

    while (cin >> word) {
        if (excludes.find(word) == excludes.end()) 
            ++words[word]; 
    }

    for (const auto &item : words) {
        cout << item.first << " occurs : " << item.second 
            << ((item.second > 1) ? "times" : "time" )<< endl;
    
    }

    return 0;
}

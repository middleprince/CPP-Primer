#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

void printPair(const pair<string, string> &the_pair) {
    cout << "name is: " << the_pair.first << "  birthday is: " << the_pair.second << endl;
}

int main() {
    string word, birthday, family_name;
    vector<pair<string, string>> childrend;
    pair<string, string> temp;

    cin >> family_name;
    while (cin >> word >> birthday)  {
        temp = make_pair(word, birthday); 
        childrend.push_back(temp);
    }

    map<string, vector<pair<string, string> > > family{{family_name, childrend}};

    for (const auto &item : family) {
        cout << "Family name is : " << item.first << endl; 
        cout << "These childrend are in the family is showing below: \n";
        
        for (const auto &child : item.second) 
            printPair(child);
        cout << endl;
    } 

    return 0;
}


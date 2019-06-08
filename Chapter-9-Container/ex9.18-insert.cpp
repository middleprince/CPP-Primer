#include <deque>
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main() {
    deque<string> que_in;
    list<string> li_in;
    string word;
    while (cin >> word) { 
        que_in.push_back(word);
        li_in.push_back(word);
    }
    
    for (const auto &item : que_in)
        cout << item << " ";
    cout << endl; 
    for (const auto &item : que_in)
        cout << item << " ";
    cout << endl;
    return 0;
}

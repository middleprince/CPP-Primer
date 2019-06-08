#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main() {
    vector<string> vecl{"hello", "you"}; 
    list<string> lv("yo", "hi");
    auto iter = vecl.begin();
    string word;
    while (cin >> word) 
        iter = vecl.insert(iter, word);


}

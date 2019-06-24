#include <vector>
#include <string>
#include<iostream>
#include <algorithm>
#include "ex13.31swap.hpp"
using std::vector;
using std::string;
using std::cout;
using std::endl;


int main() {
    vector<HasPtr> container;
    vector<string> strs{"hello", "you", "say", "what"};

    for (const auto &item : strs){
        HasPtr temp(item);
        container.push_back(temp);
    }
    
    cout << "sort func calling" << endl;

    sort(container.begin(), container.end());
    
    cout << "Output the results: \n";
    for( auto & item: container)
        item.show();


    return 0;

    
}

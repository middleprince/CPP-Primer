#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, string> buildMap(ifstream &map_file) {
    map<string, string> transfered_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) 
            //transfered_map[key] = value.substr(1);
            transfered_map.insert({key, value.substr(1)});
        else
            throw runtime_error("No value for" + key);
    }
    return transfered_map;
}

const string &
transform(const string &anchor, const map<string, string> &maped) {
    auto found = maped.find(anchor);
    if (found != maped.cend()) 
        return found->second;
    else
        return anchor;
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto tran_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream text_stream(text); 
        string word;
        bool firstword = true;
        while (text_stream >> word) {
            if (firstword) 
                firstword = false;
            else 
                cout << " ";
            cout << transform(word, tran_map);
        }
        cout << endl;
    }
    
}

void printMap(const multimap<string, string> &map_value) {
    for (const auto &item : map_value)
        cout << "Autor is: " << item.first << "| book name: " << item.second << endl;
    
}



int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "The number of arguments must be 3" << endl;
        return -1;
    }

    ifstream map_file(argv[1]), input_file(argv[2]);
    
    word_transform(map_file, input_file);
    return 0;
}

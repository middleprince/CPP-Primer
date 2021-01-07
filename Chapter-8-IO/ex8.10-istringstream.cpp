/**
 * exercise about fstream manipulate
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void readToVector(const string &path_in, vector<string> &bottle) {
    ifstream in(path_in); 
    if(!in) 
        cerr << "File open error" << endl;
    string line;
    while (getline(in, line)) {
        bottle.push_back(line); 
    }
    in.close();
}

int main(int argc, char **argv) {
    vector<string> the_bottle;
    string word;
    if (argc != 2)
        cerr << "the numbers of argument must be one" << endl;
    readToVector(argv[1], the_bottle);
    for (auto &strs : the_bottle) {
        istringstream the_str(strs);
        while(the_str >> word)
            cout << word << endl;
    }
    return 0;
    
}

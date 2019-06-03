/**
 * exercise about fstream manipulate
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void readToVector(const string &path_in, vector<string> &bottle) {
    ifstream in(path_in); 
    if(!in) 
        cerr << "File open error" << endl;
    string line;
    while (getline(in, line))
       bottle.push_back(line);
    in.close();
}

int main(int argc, char **argv) {
    vector<string> the_bottle;
    if (argc != 2)
        cerr << "the numbers of argument must be one" << endl;
    readToVector(argv[1], the_bottle);
    for (auto &str : the_bottle)
        cout << str << endl;

    return 0;
    
}

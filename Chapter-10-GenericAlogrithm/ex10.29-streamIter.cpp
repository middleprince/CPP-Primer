#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    if (argc < 1){
        cerr << "arg must be 2\n";
        return -1;
    } 
    ifstream the_file(argv[1]);
    istream_iterator<string> beg(the_file) , end;
    vector<string> strs(beg, end);

    cout << "# Data in that fie is: \n";
    for (const auto &item : strs)
        cout << item << " ";
    cout << endl;

    return 0;
}

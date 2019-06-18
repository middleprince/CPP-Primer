#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    if (argc != 4){
        cerr << "arg must be 3, one input file path and two out put path\n";
        return -1;
    } 
    ifstream the_file(argv[1]);
    ofstream out_file1(argv[2]);
    ofstream out_file2(argv[3]);

    istream_iterator<int> beg(the_file) , end;
    ostream_iterator<int> out_odd(out_file1, " ");
    ostream_iterator<int> out_even(out_file2, "\n");

    while (beg != end) {
        if (*beg % 2 == 0)
            out_even = *beg;
        else 
            out_odd = *beg; 
        ++beg;
    }
    

    cout << "# Data in odd file is: \n";

    return 0;
}

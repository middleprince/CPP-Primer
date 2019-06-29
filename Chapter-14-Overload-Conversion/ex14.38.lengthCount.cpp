#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class WordCount {
    size_t len;
public:
    WordCount(size_t n) : len(n) {}
    bool operator() (const string &s) {
        return s.length() == len;}
};

int main(int argc, char **argv) {
    if (argc != 2)
        throw runtime_error("Argument numbers must be 2");
    ifstream fin(argv[1]);
    
    int quantity9 = 0; 
    WordCount count(9);
    
    for (string word; fin >> word; ) {
        if (count(word)) 
            ++quantity9;
    }

    cout << "the numbers of word which length is 9 :" << endl;
    cout << "number is: " << quantity9 << endl;



}

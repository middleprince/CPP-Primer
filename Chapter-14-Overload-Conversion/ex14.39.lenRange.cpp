#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class WordCount {
    size_t low, up;
public:
    WordCount(size_t l = 0, size_t u = 0) : low(l), up(u) {}
    bool operator() (const string &s) {
        return low <= s.length() && s.length() <= up; }
};

int main(int argc, char **argv) {
    if (argc != 2)
        throw runtime_error("Argument numbers must be 2");
    ifstream fin(argv[1]);
    
    int quantity19 = 0; 
    int quantity10 = 0; 
    WordCount count19(1, 9);
    WordCount count10(10, 10);
    int total = 0;
    
    for (string word; fin >> word; ) {
        ++total;
        if (count19(word)) { 
            ++quantity19;
        }
        else if (count10(word))
            ++quantity10;
    }

    cout << "the numbers of word which length range 1 to 9 :" << endl;
    cout << "number is: " << quantity19 << endl;
    
    cout << "the numbers of word which length above 10 :" << endl;
    cout << "number is: " << total - quantity10 - quantity19 << endl;

    return 0;
}

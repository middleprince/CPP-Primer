#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> ints;
    istream_iterator<int> data_in(cin), end;
    ostream_iterator<int> data_out(cout, " "); 
   
    while(data_in != end) {
        ints.push_back(*data_in++);
        
    }
   
    sort(ints.begin(), ints.end(), [](const int &a, const int &b) {return a < b;} ); 
    cout << "# Data after sort is showing below: \n";
    
    unique_copy(ints.cbegin(), ints.cend(), data_out);

    return 0;
}

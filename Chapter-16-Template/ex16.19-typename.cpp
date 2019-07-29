#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;


template <typename Container>
void print(std::ostream & os, const Container &con) {
    using size_type = typename Container::size_type;
    for (size_type item = 0; item != con.size(); ++item)    
        os << con.at(item) << " ";
    cout << endl;
}

int main() {
    vector<int> intVec{1, 2, 3, 4, 1000}; 
    string strs{"hello"}; 
    
    print(cout, intVec);
    print(cout, strs);
    return 0;
}

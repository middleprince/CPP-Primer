#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &to_print) {
    for (const auto &item : to_print) 
        cout << item << " ";
    cout << endl;

}

int main() {
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "The original vector showing below: \n"; 
    print(vi);
    cout << endl;

    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            // the iter old will be invalid after the insert operation
            //iter = vi.insert(iter, *iter++); 
            iter++ = vi.insert(iter, *iter); 
            //cout << "debug: *iter++, iter is: " << *iter << "\n";
            
            // same as iter = vi.insert(iter, *iter); for vector the iterator before
            // the position of the inserted item will be still valid
            // vi.insert(iter, *iter); 
            
            iter += 1;
            //cout << "debug: after iter plus is: " << *iter << "\n";
        } else
            iter = vi.erase(iter);
    }
    cout << "The vector manpulated showing below: \n";
    print(vi);
    
    return 0;
}

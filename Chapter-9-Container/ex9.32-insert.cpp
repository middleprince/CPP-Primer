#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &to_print) {
    cout << "#Test: \n";
    for (const auto &item : to_print) 
        cout << item << " ";
    cout << endl;

}

int main() {
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter++); 
            iter += 1;
        } else
            iter = vi.erase(iter);
    }
    return 0;
}

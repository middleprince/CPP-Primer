#include <iostream>
#include <vector>

using namespace std;

void getInput(vector<int> *vec_ptr) {
    int temp;
    while (cin >> temp)
        vec_ptr->push_back(temp);

}

void printOut(vector<int> *vec_ptr) {
    for (const auto &item : *vec_ptr)
        cout << item << " ";
    cout << endl;

}
int main() {
    vector<int> *vec_ptr = new(vector<int>);
    getInput(vec_ptr);
    printOut(vec_ptr);
    
    return 0;
}


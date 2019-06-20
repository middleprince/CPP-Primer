#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void getInput(shared_ptr<vector<int> > vec_ptr) {
    int temp;
    while (cin >> temp)
        vec_ptr->push_back(temp);

}

void printOut(shared_ptr<vector<int> > vec_ptr) {
    for (const auto &item : *vec_ptr)
        cout << item << " ";
    cout << endl;

}
int main() {
    auto vec_ptr = make_shared<vector<int> >();
    getInput(vec_ptr);
    printOut(vec_ptr);
    
    return 0;
}


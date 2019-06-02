#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;


int add(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int dev(int a, int b) {
    return a / b;
}

int main() {
    vector<decltype(add) *> funcVector;
    funcVector.push_back(add);
    funcVector.push_back(sub);
    funcVector.push_back(mul);
    funcVector.push_back(dev);

    for(auto &func : funcVector) {
        cout << "Result is : " << func(4, 2) << endl;     
    }
    return 0;
}

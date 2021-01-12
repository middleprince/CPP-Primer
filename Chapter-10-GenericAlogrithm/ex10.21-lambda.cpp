#include <iostream>

using namespace std;

int main() {
    int a = 4;
    auto f = [=] ()mutable -> bool {
        if (a > 0){
            --a;
            return true;
        }
        else
            return false;
        };
    cout << "# Test for lambda f:\n";
    bool state;
    while ((state=f())){
        cout << "The int in lambda state is not zero: " << state;
        cout << endl;
    }
    cout << "The int in lambda state is zero: " << state;
    return 0;
}

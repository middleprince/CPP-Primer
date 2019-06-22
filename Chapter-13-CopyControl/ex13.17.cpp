#include <iostream>

using namespace std;

class numbered {
 public:  
    int mysn;
    numbered() {
        static int unique_number = 10;
        mysn = ++unique_number; 
    }
    numbered(const numbered &old) { mysn = old.mysn + 1;}
};

void f(numbered a) {
    cout << a.mysn << endl;
}

int main() {
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}

#include <iostream>
#include <string>
#include <memory>

using namespace std;

void catString(const string &s1, const string &s2, char *&des) {
    string temp = s1 + s2;
    int i = 0;
    for (const auto &item : temp) 
        des[i++] = item; 
}

int main() {
    string str1{"hello"};
    string str2{" you"};
    
    char *cated = new char[128];
    
    catString(str1, str2, cated);
    cout << "concatenated string is :\n";
    cout << string(cated) << endl;

    catString("so", "waht", cated);
    cout << "Concatenate to liter string\n";
    cout << string(cated) << endl;
    return 0;
}

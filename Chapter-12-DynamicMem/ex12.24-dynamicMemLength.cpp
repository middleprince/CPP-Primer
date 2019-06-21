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
    string str1;
    string str2;
    string length_str;
    
    cin >> str1 >> str2 >> length_str; 

    char *cated = new char[5];
    
    char *length_char = new char[5];
    int i = 0;
    for (const auto &item : length_str)
        length_char[i++] = item;
    
    catString(str1, str2, cated);
    cout << "concatenated string is :\n";
    cout << string(cated) << endl;

    cout << "Test for length larger than 5:\n";
    cout << string(length_char) << endl;

    return 0;
}

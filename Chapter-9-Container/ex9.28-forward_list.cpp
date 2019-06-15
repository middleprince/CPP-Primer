#include <forward_list>
#include <iostream>

using namespace std;

void listRepalce(forward_list<string> &f_list, const string &s1, const string &s2) {
    auto prev = f_list.before_begin();
    auto curr = f_list.begin();

    bool found = false;
    while (curr != f_list.end()) {
        if (*curr == s1) {  
            f_list.insert_after(prev, s2);
            found = true;
            break;
        } 
        prev = curr;
        ++curr;
    }

    if (!found)
        f_list.insert_after(prev, s2);
}

int main() {
    forward_list<string > val_fl{"Hello", "you", "see"};
    string s1{"you"};
    string s2{"replaced"};

    cout << "#Test original string is: \n";
    for (const auto &item : val_fl)
        cout << item << " ";
    cout << "\n\n";

    cout << "s1 is: " << s1 << "\ts2 is: " << s2 << "\n\n";
    listRepalce(val_fl, s1, s2);
    
    cout << "The result showing below: " << "\n";
    cout << "# final string is: \n";
    for (const auto &item : val_fl)
        cout << item << " ";
    cout << endl;
    
    return 0;
}

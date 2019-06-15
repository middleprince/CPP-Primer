#include <iostream>
#include <string>

using namespace std;

void strReplace(string &strs, const string &old_val, const string &new_val) {
    auto p = strs.begin();

    while (p != strs.end()) {
        auto p1 = old_val.begin();
        bool found = false;
        while (p1 != old_val.end() && p != strs.end()) {
            if (*p == *p1) {
                ++p;
                ++p1;
                if (p1 == old_val.end()) {
                    found = true;
                    break;
                }
            } else {
                ++p;
                p1 = old_val.begin();
            }
        }
        if (found) {
            string::size_type t = old_val.size();
            auto pre_p = p;
            while (t--)
                --pre_p;

            auto curr =  strs.erase(pre_p, p);
            strs.insert(curr, new_val.begin(), new_val.end());
        }
    
    }

}

int main () {
    string sstr{"hello tho tho"};
    string ancor{"tho"};
    string target{"though"};

    cout << "#Test original words shoeing below: \n";
    cout << sstr << endl;
    
    strReplace(sstr, ancor, target); 
    cout << "After replace, words showing below \n: ";
    cout << sstr << endl;


    return 0;
}

#include <iostream>
#include <string>

using namespace std;

void strReplace(string &strs, const string &old_val, const string &new_val) {
    string::size_type p = 0;

    while (p != strs.size()) {
        string::size_type p1 = 0;
        bool found = false;
        while (p1 != old_val.size() && p != strs.size()) {
            if ( strs[p]== old_val[p1]) {
                ++p;
                ++p1;
                if (p1 == old_val.size()) {
                    found = true;
                    break;
                }
            } else {
                ++p;
                p1 = 0;
            }
        }
        if (found) {
            strs.replace(p-old_val.size(), old_val.size(), new_val);
                    }
    }

}

int main () {
    string sstr{"hello tho tho the door tho the tunel"};
    string ancor{"tho"};
    string target{"though"};

    cout << "#Test original words shoeing below: \n";
    cout << sstr << endl;
    
    strReplace(sstr, ancor, target); 
    cout << "After replace, words showing below \n ";
    cout << sstr << endl;


    return 0;
}

#include <list>
#include <string>
#include <vector>
using namespace std;

int main() {
    list<const char *> vl{"hello", "you"};
    vector<string> vv;
    vv.assign(vl.begin(), vl.end());
    vector<int> vin(10,2);
    // two contianer type must be same and the element number type also must be 
    // same if using container type assingment
    // Instead, using numbers to intialize diffdrent type contianer will be ok
    vector<double> vdou(vin.begin(), vin.end());

    return 0;
}

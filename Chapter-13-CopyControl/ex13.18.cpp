#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Employee {
public:
    Employee() {
        ++type_id;
        cout << "Id is: " << type_id << endl; 
    }

    Employee(const string &name_in) : name(name_in) {
        ++type_id;
        cout << "Id is:" << type_id << endl; 
    }
        
private:
    string name;
    static int type_id;

}; 

int Employee::type_id = 0;

int main() {
   Employee m1; 
   Employee m2("micheal");
   return 0;

}

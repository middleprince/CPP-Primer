#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::istream;
using std::ostream;

class Person;

class Person {
    
public:
    typedef string::size_type item;
    
    friend istream &read(istream &, Person &);
    friend ostream &print(ostream &, const Person &);

    //Person() = default;
    // The defualt constructor with defualt aurgument
    // Attention The default argument constructor must can not be more 
    // one!!! If it is, the compiler is unablie to choose the right one
    Person(const string &name_in = "theDefault Name") : name(name_in) { 
        cout << "This is constructor param1 name is:" << name << std::endl; 
        ++cnt;
    }
    Person(const string &name_in, const string &tel_in, const string &addre_in) 
            : name(name_in), tel(tel_in), addre(addre_in) {
                cout << "This is constructor param3 name is:  " << name
                        << std::endl; 
                ++cnt;

    } 
    Person(const string &name_in, const string &tel_in) : Person(name_in, 
            tel_in, "") {
        cout << "This is constructor delegate  param2 name is:" << name 
                << std::endl;
        ++cnt;
    }
    Person(istream &is = std::cin, const string &msg = "Defual stream");

    void modifyInfoName(const string &name_in);
    void modifyInfoTel(const string &tel_in);
    void modifyInfoAddre(const string &addre_in);

private:
    string name;
    string tel;
    string addre;
    mutable item cnt = 0;

};



inline void Person::modifyInfoName(const string &name_in) {
    name = name_in;    
    ++cnt;
}

inline void Person::modifyInfoTel(const string &tel_in) {
    tel = tel_in;    
    ++cnt;
}

inline void Person::modifyInfoAddre(const string &addre_in) {
    addre = addre_in;    
    ++cnt;
}

istream &read(istream &is, Person &p) {
    is >> p.name >> p.tel >> p.addre;
    return is;
}

ostream &print(ostream &os, const Person &p)  {
    os << p.name << " " << p.tel << " " << p.addre << std::endl;   
    return os;
}

inline Person::Person(istream &is, const string &msg) {
    read(is, *this);
    cout << "This is constructor stream msg is: " << msg << std::endl;
    ++cnt;
}


int main() {
    std::vector<Person *> temp; 

    Person p1;
    temp.push_back(&p1);

    Person p2("Wang Er");
    temp.push_back(&p2);

    Person p3("Li Si", "323131231", "BeiJing China");
    temp.push_back(&p3);

    Person p4("Liu Jiu", "2313213");
    temp.push_back(&p4);

    Person p5(std::cin, "Hello");
    temp.push_back(&p5);

    p2.modifyInfoTel("19292929");
    p2.modifyInfoAddre("Phnixy Road Mars");

    //read(std::cin, p1);

    p4.modifyInfoAddre("p4 road ");
    
    cout << std::endl;

    for (auto pp : temp) 
        print(cout, *pp);
    
    return 0;
}

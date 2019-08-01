#include "ex16.16.Vec.hpp"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main() {
    Vec<string> strVec{"hello", "it's", "me", "and", "you"};
    Vec<int> intVec{100, 200, 300, 400};
   
    cout << "#########  Test for Vec<string>" << endl;
    
    cout << "## Test for copy assignment  \n"; 
    Vec<string> strVec2;
    strVec2 = strVec;
    cout << "strVec is: ";
    for (const auto& item : strVec) cout << item << " ";
    cout << endl;

    cout << "strVec2 is:";
    for (const auto& item : strVec2) cout << item << " ";
    cout << endl;
        
    cout << "## Test for oprator[] \n";
    cout << "strVec[2] expected output: me\n";
    cout << "result is: " << strVec[2] << endl;

    cout << "## Test for at \n";
    cout << "strVec.at(1) expected output: it's\n";
    cout << "result is: " << strVec.at(1) << endl;
    
    cout << "## Test for push_back() \n";
    strVec.push_back("new");
    cout << "strVec is: ";
    for (const auto& item : strVec) cout << item << " ";
    cout << endl;
    
    cout << "## Test for function size \n" 
         << "strVec size is: " << strVec.size() << endl;
   
    cout << "## Test for function capacity \n" 
         << "strVec capacity is: " << strVec.capacity() << endl;
   
    // Test for resize
    cout << "## Test for function resize \n"
         << "A. before resize, size is: " << strVec.size() << endl; 
    strVec.resize(12);
    cout << "B. after resize, size is: " << strVec.size() << "\n"
         << "C. after resize, capacity is: " << strVec.capacity() << endl;
    
    cout << "\n\n" << endl;
    //=================================================================================== 
    //Test for Vec<int>
    //=================================================================================== 
   
    cout << "#########  Test for Vec<int> ########\n" << endl;
   
    cout << "## Test for copy assignment  \n"; 
    Vec<int> intVec2;
    intVec2 = intVec;
    cout << "intVec is: ";
    for (const auto& item : intVec) cout << item << " ";
    cout << endl;
    cout << "intVec2 is:";
    for (const auto& item : intVec2) cout << item << " ";
    cout << endl;
        
    cout << "## Test for oprator[] \n";
    cout << "intVec[2] expected output: 300\n";
    cout << "result is: " << intVec[2] << endl;

    cout << "## Test for at \n";
    cout << "intVec.at(1) expected output: 200\n";
    cout << "result is: " << intVec.at(1) << endl;
    
    cout << "## Test for push_back() \n";
    intVec.push_back(2019);
    cout << "intVec is: ";
    for (const auto& item : intVec) cout << item << " ";
    cout << endl;

    cout << "## Test for function size \n" 
         << "intVec size is: " << intVec.size() << endl;
   
    cout << "## Test for function capacity \n" 
         << "intVec capacity is: " << intVec.capacity() << endl;
   
    // Test for resize
    cout << "## Test for function resize \n"
         << "A. before resize, size is: " << intVec.size() << endl; 
    intVec.resize(14);
    cout << "B. after resize, size is: " << intVec.size() << "\n"
         << "C. after resize, capacity is: " << intVec.capacity() << endl;
    cout << "After resize contents showing below: \n"; 
    for (const auto& item : intVec) cout << item << " ";
    
    return 0;
}

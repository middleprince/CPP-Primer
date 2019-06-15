#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string findNumChaFrist(const string &strs_in) {
    string results{""};
    string strs = strs_in;
    std::transform(strs.begin(), strs.end(), strs.begin(), ::tolower);
    //cout << "##Debug lower string is: \n" << strs << endl;
    
    string number{"0123456789"};
    string chars; 
    
    char c = 'a'; 
    for (int i=0; i<26; ++i) {
        chars.push_back(c);
        ++c;
    }
    //cout << "##Debug chars is:\n" << chars << endl;
    

    string::size_type t=0;
    while ( t < strs.size()) {
        auto index = strs.find_first_of(number, t); 
        if (index != string::npos) {
            //cout << "## debug number: \n" << strs_in[index] << endl;
            results.push_back(strs_in[index]); 
            results.push_back(' ');
            t = index+1;
        } else
          ++t;  
    } 
   
    t = 0; 
    while (t < strs.size()) {
        auto index = strs.find_first_of(chars, t); 
        if (index != string::npos) {
            //cout << "## debug Char: \n" << strs_in[index] << endl;
            results.push_back(strs_in[index]); 
            results.push_back(' ');
            t = index+1;
        } else
            ++t;
    }
    return  results;
}


string findNumChaFristNot(const string &strs_in) {
    string results{""};
    string strs = strs_in;
    std::transform(strs.begin(), strs.end(), strs.begin(), ::tolower);
    //cout << "##Debug lower string is: \n" << strs << endl;
    
    string number{"0123456789"};
    string chars; 
    
    char c = 'a'; 
    for (int i=0; i<26; ++i) {
        chars.push_back(c);
        ++c;
    }
    //cout << "##Debug chars is:\n" << chars << endl;
    

    string::size_type t=0;
    while ( t < strs.size()) {
        auto index = strs.find_first_not_of(number, t); 
        if (index != string::npos) {
            //cout << "## debug number: \n" << strs_in[index] << endl;
            results.push_back(strs_in[index]); 
            results.push_back(' ');
            t = index+1;
        } else
          ++t;  
    } 
   
    t = 0; 
    while (t < strs.size()) {
        auto index = strs.find_first_not_of(chars, t); 
        if (index != string::npos) {
            //cout << "## debug Char: \n" << strs_in[index] << endl;
            results.push_back(strs_in[index]); 
            results.push_back(' ');
            t = index+1;
        } else
            ++t;
    }
    return  results;
}

int main () {
    
    string strs{"ab2c3d7R4E6"};

    cout << "#Test data to be search is :\n";
    cout << strs << "\n" << endl;

    cout << "The number and char found are showing below:\n";
    cout << "using inf_frist() : ";
    cout << findNumChaFrist(strs) << endl;

    cout << "using find_first_not_of() : ";
    cout << findNumChaFristNot(strs) << endl;
        
        
    return 0;    
}

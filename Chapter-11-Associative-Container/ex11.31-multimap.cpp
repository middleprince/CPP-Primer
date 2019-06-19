#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool deleteAuthor(multimap<string, string> &books_dic, const string &name) {
    auto entries = books_dic.count(name);
    //cout << "#debug entries is : " << entries << endl;

    if (entries == 0){
        return false;
    }
    
    auto index = books_dic.find(name);
    while (entries) {
        index = books_dic.erase(index); 
        --entries;
    }
    return true;
}

void printMap(const multimap<string, string> &map_value) {
    for (const auto &item : map_value)
        cout << "Autor is: " << item.first << "| book name: " << item.second << endl;
    
}

void inputMap(multimap<string, string> &map_value) {
    string name;
    string book_name;
    size_t n_books;

    while (cin >> name && name != "end" && cin >> n_books) {
        while (n_books-- && cin >> book_name)
            map_value.insert({name, book_name});
    }
}

int main() {
    multimap<string, string> books_list;
    inputMap(books_list);    
    string name;

    cout << "The Dic is:\n";
    printMap(books_list);
    cout << endl;

    cout << "Input the author whose books you want to remove \n"; 
    cin >> name;
    if (!deleteAuthor(books_list, name)) {
        cerr << "Error: the name you input is not exist in book dic: " << name <<  endl;
        return -1;
    } else {
        cout << "Dic after removed the author: " << name << "showing as:\n";
        printMap(books_list);
        cout << endl;
        return 0;
    }
}

#include "ex15.26.CopyControl.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    cout << "Constructor msg Test" << endl;
    Quote book1("base book", 18.8);
    Bulk_Quote book2("Bulk book", 28.8, 20, 0.88);
    Up_Quote book3("Up book", 38.8, 20, 35, 0.77);
    cout << endl;

    cout << "Copy control constructor msg Test" << endl;
    Quote book1_copy(book1);
    Bulk_Quote book2_copy(book2);
    Up_Quote book3_copy(book3);
    cout << endl;
 
    cout << "Assigment copy constructor msg Test" << endl;
    Quote book1_copy_assn = book1;
    Bulk_Quote book2_assn = book2;
    Up_Quote book3_assn = book3;
    cout << endl;

    cout << "Mov control constructor msg Test" << endl;
    Quote book1_copy_mov(std::move(book1));
    Bulk_Quote book2_copy_mov(std::move(book2));
    Up_Quote book3_copy_mov(std::move(book3));
    cout << endl;
 
    cout << "Move copy constructor msg Test" << endl;
    Quote book1_ass_mov = std::move(book1);
    Bulk_Quote book2_ass_mov = std::move(book2);
    Up_Quote book3_ass_mov = std::move(book3);
    cout << endl;

    return 0;
}

#include "ex13.34message.hpp"

int main() {
    Message mail1("hello my name is 1");
    Message mail2("yo i'm 2");

    Folder mailBox;

    mail1.printMsg();
    mail1.save(mailBox);
    mailBox.printMsg();


    mail2.printMsg();
    mail2.save(mailBox);
    mailBox.printMsg();
     
    mail1 = mail1;
    mail1.printMsg();
    mailBox.printMsg();

    Message mail3 = mail1;
    mail3.save(mailBox);
    mailBox.printMsg();

    cout << "remove mail2\n";
    mail2.remove(mailBox);
    mailBox.printMsg();
    
    return 0;
}

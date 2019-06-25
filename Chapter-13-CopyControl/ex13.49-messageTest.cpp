#include "ex13.49movemessage.hpp"

int main() {
    Message mail1("hello i'm mail 1\n");
    Message mail2("hello my name is 2\n");

    Folder mail_box;

    mail1.save(mail_box);
    mail2.save(mail_box);
    mail_box.printMsg();

    Message mail3 = std::move(mail1);
    cout << "after move assign mail1 to mail3, the contents of mail1 showing: \n";
    mail1.printMsg();

    cout << "contents in mail box showing\n";
    mail_box.printMsg();
   
   return 0; 

}

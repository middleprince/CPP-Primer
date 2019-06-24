#ifndef ex13_34message_h
#define ex13_34message_h

#include <string>
#include <set>
#include <iostream>

using std::string;
using std::set;
using std::cout;
using std::endl;

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    
public:
    explicit Message(const string &strs = string()) 
        : contents(strs) {}
    Message(const Message &);
    Message & operator=(const Message &);
     ~Message();

     void save(Folder &);
     void remove(Folder &);

     void printMsg();
    
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folder(const Message&);
    void remove_from_Folder();

};

void swap(Message&, Message&);

class Folder {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder&);
    Folder & operator=(const Folder&);
    ~Folder();

    void printMsg();

private:
    set<Message*> msgs;

    void add_to_Messages(const Folder&);
    void remove_from_Messages();

    void addMsg(Message *m) {msgs.insert(m);}
    void remMsg(Message *m) {msgs.erase(m);}

};


void swap(Folder&, Folder&);

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

Message::Message(const Message &old) 
    : contents(old.contents), folders(old.folders) {
        add_to_Folder(old); 
    }

Message & Message::operator=(const Message &rval) {
    remove_from_Folder();
    contents = rval.contents;
    folders = rval.folders;
    add_to_Folder(rval);
    return *this;
}

Message::~Message() {
    remove_from_Folder();
}

// add message into the folder f
void Message::save(Folder &f) {
    folders.insert(&f);   
    f.addMsg(this);
}

// remove message from folder f
void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

// tool function, add message pointer to folders
void Message::add_to_Folder(const Message &m) {
    for (auto &f : m.folders)
        f->addMsg(this);
}

// tool function, remove message pionter according to folders 
void Message::remove_from_Folder() {
    for (auto &f : folders)
        f->remMsg(this);
}

void Message::printMsg() {
    cout << contents << endl;
}

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    lhs.remove_from_Messages();
    rhs.remove_from_Messages();

    swap(lhs.msgs, rhs.msgs);

    lhs.add_to_Messages(lhs);
    rhs.add_to_Messages(rhs);
}

Folder::Folder(const Folder &f) : msgs(f.msgs) {
    add_to_Messages(f);
}

Folder & Folder::operator=(const Folder &rhs) {
    remove_from_Messages();
    msgs = rhs.msgs;
    add_to_Messages(rhs);
    return *this;
}

Folder::~Folder() {
   remove_from_Messages();
}

// tool function
// add the current Folder pointer to other Folder's message's folders 
void Folder::add_to_Messages(const Folder &f) {
    for (auto m : f.msgs)
        m->folders.insert(this);
}

// tool function
// remove Folder infon from messages
void Folder::remove_from_Messages() {
    for (auto m : msgs)
        m->folders.erase(this);
}

void Folder::printMsg() {
    for (auto m : msgs)
        cout << m->contents << " ";
   cout << endl; 
}
    


#endif

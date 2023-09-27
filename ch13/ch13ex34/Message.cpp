#include "Message.h"
#include "Folder.h"

//Copy Constructor
Message::Message(const Message &m): 
    contents(m.contents), folders(m.folders)
    {add_to_folders(m);} //add THIS message to ALL folders that m is in.
//Copy Assignment
Message& Message::operator=(const Message &rhs){
    //handle self-assignment by removing pointers before inserting them
    remove_from_folders();      //update existing folders
    contents = rhs.contents;    //copy message contents from rhs
    folders = rhs.folders;      //copy Folder pointer from rhs
    add_to_folders(rhs);        //add this message to those Folders
    return *this;
}
//Destructor
Message::~Message(){
    remove_from_folders();
}

void Message::addFdr(Folder *f){
    folders.insert(f);
}
void Message::remFdr(Folder *f){
    folders.erase(f);
}

void Message::save(Folder &f){
    folders.insert(&f); //add given folder to set of folders
    f.addMsg(this);     //add this message to the folder
}

void Message::remove(Folder &f){
    folders.erase(&f);  //remove f from folder set
    f.remMsg(this);     //remove this Message from f
}

//add this message into all folders message m is in
void Message::add_to_folders(const Message &m){
    for(auto f : m.folders){
        f->addMsg(this);
    }
}

//remove this message from all folders
void Message::remove_from_folders(){
    for(auto f: folders){
        f->remMsg(this);
    }
}

void swap(Message &lhs, Message &rhs){
    using std::swap;
    //remove pointers to each message from original respective folders
    for (auto f: lhs.folders){
        f->remMsg(&lhs);
    }
    for (auto f: rhs.folders){
        f->remMsg(&rhs);
    }
    //swap
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    //add pointers to each message to their new respective folders
    for (auto f: lhs.folders){
        f->addMsg(&lhs);
    }
    for (auto f: rhs.folders){
        f->addMsg(&rhs);
    }


}

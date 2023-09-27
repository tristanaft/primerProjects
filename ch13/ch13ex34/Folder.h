#ifndef FOLDER_H
#define FOLDER_H

#include<set>

class Message;

class Folder{
friend class Message;
friend void swap(Folder &, Folder &);
friend void swap(Message&, Message&);

public:
    //default constructor
    Folder() = default;
    //copy control to manage pointers to this message
    Folder(const Folder&);                //copy constructor
    Folder& operator=(const Folder&);     //copy assignment
    ~Folder();                             //destructor

    void save(Message&);
    void remove(Message&);

private:
    std::set<Message*> messages;
    void remMsg(Message*);
    void addMsg(Message*);
};






#endif
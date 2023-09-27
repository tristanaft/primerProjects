#ifndef MESSAGE_H
#define MESSAGE_H

#include<string>
#include<set>
#include<utility>
#include<iostream>

class Folder; //declare Folder before use below

class Message{
    friend class Folder;
    friend void swap(Message&, Message&);
    friend void swap(Folder &, Folder &);
public:
    //folder implicitly initialized to empty set
    explicit Message(const std::string &str = ""): contents(str) { }

    //copy control to manage pointers to this message
    Message(const Message&);                //copy constructor
    Message& operator=(const Message&);     //copy assignment
    ~Message();                             //destructor

    //add/remove this message from specified Folder
    void save(Folder&);
    void remove(Folder&);

private:
    std::string contents; //actual message text
    std::set<Folder*> folders; //the folders that have this message

    //utility functions used by copy constructor, assignment and destructor
    void add_to_folders(const Message&); //adds this Message to Folders that point to parameter
    void remove_from_folders(); //remove this Message from every Folder in folders
    void addFdr(Folder*);
    void remFdr(Folder*);



};





#endif
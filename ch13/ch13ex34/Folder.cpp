#include "Folder.h"
#include "Message.h"

//something seems a bit off...
//why does remove need *this instead of this?
//I think it still does what I want it to, but in a bit of a weird way?

//copy constructor
Folder::Folder(const Folder& f): messages(f.messages){
    for(auto m: messages){
        m->folders.insert(this);
    }
}  
//copy assignment              
Folder& Folder::operator=(const Folder& rhs){
    for(auto m: messages){ //for each message
        m->remove(*this); //remove this folder from them
    }
    messages = rhs.messages; //copy messages from rhs
    for(auto m: messages){ //update each message to be in this file
        m->save(*this);
    }
    return *this;
} 
//destructor    
Folder::~Folder(){
    for(auto m : messages){ //for each message contained in folder
        m->folders.erase(this);   //remove folder from message
    }
}    

void Folder::addMsg(Message* m){
    messages.insert(m);
}
void Folder::remMsg(Message* m){
    messages.erase(m);
}

void Folder::save(Message &m){
    messages.insert(&m);
    m.folders.insert(this);
}
void Folder::remove(Message&m){
    messages.erase(&m);
    m.folders.erase(this);
}

void swap(Folder &lhs, Folder &rhs){
    using std::swap;

    for(auto m: lhs.messages){
        m->remove(lhs);
    }
    for(auto m: rhs.messages){
        m->remove(rhs);
    }

    swap(lhs.messages,rhs.messages);

    for(auto m: lhs.messages){
        m->save(lhs);
    }
    for(auto m: rhs.messages){
        m->save(rhs);
    }
}

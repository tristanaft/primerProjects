#include<string>
#include<vector>
#include<memory>
#include <initializer_list>

#ifndef STRVEC_H
#define STRVEC_H

class StrVec{
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);

public:
    StrVec(): //the allocator member is default initialized
    elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string>);
    StrVec& operator=(std::initializer_list<std::string>);
    StrVec(const StrVec&);              //copy constructor
    StrVec& operator=(const StrVec&);   //copy assignment
    ~StrVec();                          //destructor
    void push_back(const std::string&); //copy the element
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    std::string* begin() const {return elements;}
    std::string* end() const {return first_free;}

private:
    static std::allocator<std::string> alloc; //allocates the elements
    void chk_n_alloc(){if(size() == capacity()) reallocate();}; //used by func that add elements to a StrVec
    //utilities used by copy constructor, assignment operator and destructor
    std::pair<std::string*,std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();        //destroy elements and free space
    void reallocate();  //get more space and copy existing elements
    std::string* elements;
    std::string* first_free;
    std::string* cap;

};

std::allocator<std::string> StrVec::alloc;

#endif
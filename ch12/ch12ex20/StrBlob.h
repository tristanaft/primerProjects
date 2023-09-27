#ifndef STRBLOB_H
#define STRBLOB_H

class StrBlobPtr;
#include <memory>
#include <string>
#include <vector>
#include <initializer_list>

class StrBlob{
    friend class StrBlobPtr;
public:
    StrBlobPtr begin(); //return StrBlobPtr to first element
    StrBlobPtr end(); //return StrBlobPtr to one past last element

    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const {return data -> size();};
    bool empty() const {return data -> empty();};
    void push_back(const std::string &t) {data -> push_back(t);};
    void pop_back(); //not yet added

    std::string& front();
    const std::string& front() const;
    std::string& back(); 
    const std::string& back() const; 

private:
    std::shared_ptr<std::vector<std::string>> data;
    //throws msg if data[i] is invalid
    void check(size_type i, const std::string &msg) const;


};

#endif
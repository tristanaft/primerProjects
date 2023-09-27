#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <memory>
#include <string>
#include <vector>
#include <initializer_list>

class StrBlob;


class StrBlobPtr {
    friend bool operator==(StrBlobPtr&, StrBlobPtr&);
    friend bool operator!=(StrBlobPtr&, StrBlobPtr&);
    friend bool operator<(StrBlobPtr&, StrBlobPtr&);
    friend bool operator>(StrBlobPtr&, StrBlobPtr&);
    friend bool operator<=(StrBlobPtr&, StrBlobPtr&);
    friend bool operator<=(StrBlobPtr&, StrBlobPtr&);
public:
    typedef std::vector<std::string>::size_type size_type;
    std::string& deref() const;
    StrBlobPtr& incr(); //prefix version
    //initializers
    StrBlobPtr();
    StrBlobPtr(StrBlob &a, size_t sz = 0);

private:
    //check returns a shared_ptr to the vector if check succeeds
    std::shared_ptr<std::vector<std::string>>
        check(size_type, const std::string&) const;
    
    //store a weak_ptr, so underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; //current position in array


};

#endif
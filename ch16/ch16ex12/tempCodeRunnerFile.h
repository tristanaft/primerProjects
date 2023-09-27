#include <vector>
#include <initializer_list>
#include <memory>
#include <string>
#include <stdexcept>
#include "Blob.h"


template<typename T> class BlobPtr{
friend class Blob<T>;
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T>& a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr]; //(*p) is the vector to which this object points
    }
    //I am a bit confused, since it is a weak pointer, shouldn't we have to do a lock
    //before we dereference p? OHHH we do the lock in check then, since we MUST
    //dereference in order to be able to check anything, OK...

    //increment and decrement
    //note, inside the class body we don't have to write BlobPtr<T>&,
    //we can leave off the <T>
    BlobPtr& operator++();
    BlobPtr& operator--();
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

//outside the class body, we must include the <T>
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(){
    BlobPtr ret = *this; //save curr val
    ++*this;    //advance one
    return ret; //return saved state
}
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(){
    BlobPtr ret = *this; //save curr val
    --*this;    //advance one
    return ret; //return saved state
}
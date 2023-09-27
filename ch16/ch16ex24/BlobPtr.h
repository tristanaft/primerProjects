#ifndef BLOBPTR_H
#define BLOBPTR_H

#include <vector>
#include <initializer_list>
#include <memory>
#include <string>
#include <stdexcept>
#include "Blob.h"

template <typename T> class BlobPtr;
template <typename T> class ConstBlobPtr;
template <typename T> class Blob;
//operator declarations
template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);


template<typename T> class BlobPtr{
friend class Blob<T>;
    friend bool operator==<T>(const BlobPtr&, const BlobPtr&);
    friend bool operator!=<T>(const BlobPtr&, const BlobPtr&);
    friend bool operator< <T>(const BlobPtr&, const BlobPtr&);
    friend bool operator> <T>(const BlobPtr&, const BlobPtr&);
    friend bool operator<=<T>(const BlobPtr&, const BlobPtr&);
    friend bool operator>=<T>(const BlobPtr&, const BlobPtr&);
public:
    T& operator[](std::size_t n){return (*wptr.lock())[n];}
    const T& operator[](std::size_t n) const {return (*wptr.lock())[n];}
     T& operator*() const {// dereference one-pass-end pointer is not allowed
        return (*check(curr + 1, "dereference out of range"))[curr];
    }

    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);

    BlobPtr operator+(int);
    BlobPtr operator-(int);
    BlobPtr& operator+=(int);
    BlobPtr& operator-=(int);

    typedef typename std::vector<T>::size_type size_type;
    T& deref() const;
    BlobPtr& incr(); //prefix version
    //initializers
    BlobPtr();
    BlobPtr(Blob<T> &a, size_t sz = 0);

private:
    //check returns a shared_ptr to the vector if check succeeds
    std::shared_ptr<std::vector<T>> check(size_type, const std::string&) const;
    
    //store a weak_ptr, so underlying vector might be destroyed
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr; //current position in array
};

//initializers
template <typename T> 
BlobPtr<T>::BlobPtr(): curr(0) { }
template <typename T> 
BlobPtr<T>::BlobPtr(Blob<T> &a, size_t sz): wptr(a.data),curr(sz) {}


template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}
template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){return !(lhs==rhs);}

template <typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr > rhs.curr;
}

template <typename T>
bool operator<=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){return lhs<rhs || lhs==rhs;}
template <typename T>
bool operator>=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){return lhs<rhs || lhs==rhs;}

//prefix increment and decrement
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(){
    check(curr, "Increment past end of BlobPtr");
    ++curr;
    return *this;
}
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(){
    --curr;
    check(curr, "Decrement past beginning of BlobPtr");
    return *this;
}

//postfix increment and decrement
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int){
    BlobPtr ret = *this;
    ++*this; //incrementing will perform check
    return ret;
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int){
    BlobPtr ret = *this;
    --*this; //decrementing will perform check
    return ret;
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator+(int i){
    auto temp = *this;
    if(i>=0){
        for(/**/;i!=0;--i){
            ++temp;
        }
    }else{//i is negative
        for(/**/;i!=0;++i){
                --temp;
            }
    }
    return temp;
};
template <typename T>
BlobPtr<T> BlobPtr<T>::operator-(int i){return *this + (-i);}; 
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator+=(int i){
    if(i>=0){
        for(/**/;i!=0;--i){
            ++*this;
        }
    }else{//i is negative
        for(/**/;i!=0;++i){
                --*this;
            }
    }
    return *this;

};
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator-=(int i){return *this += (-i);};

//methods
//std::shared_ptr<std::vector<T>> check(size_type, const T&) const;
template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_type i, const std::string& msg) const{
            auto ret = wptr.lock();
            if(!ret) //does vector still exist?
                throw std::runtime_error("unbound BlobPtr");
            else if(i >= (ret->size() + 1)) //are we in range
            //for some reason, the code thinks it is 1 shorter than it should be...
            //that is why the +1 is in there
                throw std::out_of_range(msg);
            //if it checks out, return a shared ptr to vector
            return ret;
        }

template <typename T>
T& BlobPtr<T>::deref() const{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::incr() {
    check(curr,"increment past end of BlobPtr");
    ++curr;
    return *this;
}

#endif
#ifndef BLOB_H
#define BLOB_H

//THIS IS MODIFIED FROM CH14EX30
//that is why it has so many operators

template <typename T> class BlobPtr;
template <typename T> class ConstBlobPtr;
template <typename T> class Blob;
//operator declarations
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator!=(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator<(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator>(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator<=(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator>=(const Blob<T> &, const Blob<T> &);

#include <memory>
#include <string>
#include <vector>
#include <initializer_list>

template<typename T>
class Blob{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob&, const Blob&);
    friend bool operator!=<T>(const Blob&, const Blob&);
    friend bool operator< <T>(const Blob&, const Blob&);
    friend bool operator> <T>(const Blob&, const Blob&);
    friend bool operator<=<T>(const Blob&, const Blob&);
    friend bool operator>=<T>(const Blob&, const Blob&);
public:
    typedef typename std::vector<T>::size_type size_type;   
    T& operator[](size_type n){return (*data)[n];}
    const T& operator[](size_type n) const {return (*data)[n];}

    BlobPtr<T> begin(); //return BlobPtr to first element
    BlobPtr<T> end(); //return BlobPtr to one past last element

    Blob();
    Blob(std::initializer_list<T> il);
    //template to supply two iterators:
    template<typename It>
    Blob(It beg, It end);


    size_type size() const {return data -> size();};
    bool empty() const {return data -> empty();};
    void push_back(const T& t) {data -> push_back(t);};
    void pop_back(); //not yet added

    T& front();
    const T& front() const;
    T& back(); 
    const T& back() const; 

private:
    std::shared_ptr<std::vector<T>> data;
    //throws msg if data[i] is invalid
    void check(size_type i, const T &msg) const;


};

//initializers
template <typename T> 
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()){ }
template <typename T> 
Blob<T>::Blob(std::initializer_list<T> il): 
    data(std::make_shared<std::vector<T>>(il)){ }
//new for this exercise:
template<typename T>
template<typename It>
    Blob<T>::Blob(It beg, It end):
        data(std::make_shared<std::vector<T>>(beg, end)){ }

//operators
template <typename T> 
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs){return *lhs.data == *rhs.data;}
template <typename T> 
bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs){return !(lhs==rhs);}
template <typename T> 
bool operator<(const Blob<T>& lhs, const Blob<T>& rhs){return *lhs.data < *rhs.data;}
template <typename T> 
bool operator>(const Blob<T>& lhs, const Blob<T>& rhs){return rhs < lhs;}
template <typename T> 
bool operator<=(const Blob<T>& lhs, const Blob<T>& rhs){return lhs==rhs || lhs<rhs;}
template <typename T> 
bool operator>=(const Blob<T>& lhs, const Blob<T>& rhs){return lhs==rhs || lhs>rhs;}

//define Blob functions
template <typename T> 
void Blob<T>::check(size_type i, const T &msg) const {
    if(i >= data -> size()){
        throw std::out_of_range(msg);
    }
}

template <typename T> 
T& Blob<T>::front() {
    check(0,"front on empty Blob");
    return data -> front();
}

template <typename T> 
const T& Blob<T>::front() const {
    check(0,"front on empty Blob");
    return data -> front();
}
template <typename T> 
T& Blob<T>::back() {
    check(0,"back on empty Blob");
    return data -> back();
}
template <typename T> 
const T& Blob<T>::back() const {
    check(0,"back on empty Blob");
    return data -> back();
}
template <typename T> 
void Blob<T>::pop_back() {
    check(0,"pop_back on empty Blob");
    data -> pop_back();
}

//reliant on BlobPtr to work
template <typename T> 
BlobPtr<T> Blob<T>::begin() {return BlobPtr<T>(*this);}
template <typename T> 
BlobPtr<T> Blob<T>::end() {return BlobPtr<T>(*this,data -> size());}









#endif
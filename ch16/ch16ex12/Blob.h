#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <initializer_list>
#include <memory>
#include <string>
#include <stdexcept>

template <typename T> class BlobPtr;
template <typename T> class ConstBlobPtr;

template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);


//manages a vector of arbitrary type
template <typename T> class Blob{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    
    //constructors
    Blob();
    Blob(std::initializer_list<T>);
    //number of elements in the Blob
    size_type size() const {return data->size();};
    bool empty() const {return data->empty();};
    
    //add and remove elements
    void push_back(const T& t) {data->push_back(t);}
    //move version
    void push_back(const T&& t) {data->push_back(std::move(t));}
    void pop_back();
    //element access from p565 sec 14.5
    T& back();
    T& operator[](size_type i);
    
    //I want to define some iterators so I can do range for loops because I'm lazy
    typename std::vector<T>::iterator begin() {return data->begin();}
    typename std::vector<T>::iterator end()  {return data->end();}
    

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type, std::string&) const;
};

//Blob constructors:

template<typename T>
Blob<T>::Blob(): data(std::make_shared(std::vector<T>())) {}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il): 
    data(std::make_shared<std::vector<T>>(il)) {}

//Operators
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
  return *lhs.data == *rhs.data;  // compare value
}

//I could include more...


//Methods

template<typename T>
void Blob<T>::check(size_type i, std::string& msg) const {
    if(i >= data -> size()){
        throw std::out_of_range(msg);
    };
}

template<typename T>
T& Blob<T>::back(){
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i){
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back(){
    check(0, "pop back on empty Blob");
    data->pop_back();
}




#endif
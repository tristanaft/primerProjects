#include<iostream>
#include<string>
#include<vector>
#include<functional>

//WIP, finish later...
//I think this exercise is way too much work for not much benefit...

template<typename T>
class shared_ptr{
public:
    //constructors
    shared_ptr(): p(new T()), count(new unsigned int(1)) {}
    shared_ptr(T* q): p(q), count(new unsigned int(1)) {}
    shared_ptr(T* q, std::function<void(T*)> del): p(q), count(new unsigned int(1)), deleter(del) {}
    shared_ptr(const shared_ptr<T>& sp): p(sp.p), count(sp.count), deleter(sp.deleter) 
        {++*count;}
    
    //dereferencing
    T& operator*() {return *p;};
    T& operator->(){return *p;};
private:
    unsigned int* count;
    T* p;
    std::function<void(T*)> deleter = [] (T* p) {delete p;};
    void check(int* c){
        if(*c == 0){
            delete p;
            delete count;
        }
    }
};

template <typename T>
class unique_ptr{
public:

//dereferencing
T& operator*() {return *p;};
T& operator->(){return *p;};
private:
    T* p;
};


int main(){

    return 0;
}

//help from https://zero4drift.github.io/posts/cpp-primer-5th-exercises-chapter-16/
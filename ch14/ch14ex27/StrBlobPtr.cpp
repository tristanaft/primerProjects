#include "StrBlobPtr.h"
#include "StrBlob.h"


//initializers
StrBlobPtr::StrBlobPtr(): curr(0) { }
StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz): wptr(a.data),curr(sz) {}

bool operator==(StrBlobPtr& lhs, StrBlobPtr& rhs){
return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}
bool operator!=(StrBlobPtr& lhs, StrBlobPtr& rhs){return !(lhs==rhs);}

bool operator<(StrBlobPtr& lhs, StrBlobPtr& rhs){
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

bool operator>(StrBlobPtr& lhs, StrBlobPtr& rhs){
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr > rhs.curr;
}

bool operator<=(StrBlobPtr& lhs, StrBlobPtr& rhs){return lhs<rhs || lhs==rhs;}
bool operator<=(StrBlobPtr& lhs, StrBlobPtr& rhs){return lhs>rhs || lhs==rhs;}

//prefix increment and decrement
StrBlobPtr& StrBlobPtr::operator++(){
    check(curr, "Increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--(){
    --curr;
    check(curr, "Decrement past beginning of StrBlobPtr");
    return *this;
}

//postfix increment and decrement
StrBlobPtr StrBlobPtr::operator++(int){
    StrBlobPtr ret = *this;
    ++*this; //incrementing will perform check
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int){
    StrBlobPtr ret = *this;
    --*this; //decrementing will perform check
    return ret;
}

//methods
std::shared_ptr<std::vector<std::string>>
        StrBlobPtr::check(size_type i, const std::string &msg) const{
            auto ret = wptr.lock();
            if(!ret) //does vector still exist?
                throw std::runtime_error("unbound StrBlobPtr");
            if(i>= ret -> size()) //are we in range
                throw std::out_of_range(msg);
            //if it checks out, return a shared ptr to vector
            return ret;
        }

std::string& StrBlobPtr::deref() const{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
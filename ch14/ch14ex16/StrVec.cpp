#include "StrVec.h"
#include<memory>
#include<utility>
#include<algorithm>

bool operator==(const StrVec& lhs, const StrVec& rhs){
    if(lhs.size() != rhs.size()){
        return false;
    }
    else{//if same size, go through elements...
        return std::equal(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    }
}

bool operator!=(const StrVec& lhs, const StrVec& rhs){return !(lhs==rhs);}

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(std::initializer_list<std::string> il): StrVec() {
    for(const auto &s: il)
        push_back(s);
}

void StrVec::push_back(const std::string& s){
    chk_n_alloc(); //ensure there is room for another element
    //construct a copy of s in the element to which first_free points
    alloc.construct(first_free++,s);
}

std::pair<std::string*,std::string*>
StrVec::alloc_n_copy(const std::string* b, const std::string* e){
//allocate data to hold as many elements as are in range
auto data = alloc.allocate(e-b);
//init and return pair from data and value returned by uninitialized_copy
//THIS LINE DOES AND SHOULD WORK BUT IT GIVES RED SQUIGGLES FOR SOME REASON
//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//return {data, std::uninitialized_copy(b, e, data)};
//I will make the pair explicitly?
return std::make_pair(data, std::uninitialized_copy(b, e, data));
}

void StrVec::free(){
    if(elements){
        for(auto p = first_free; p!= elements; /*empty*/){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap-elements);
    }
}

StrVec::StrVec(const StrVec& s){
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {free();}

StrVec& StrVec::operator=(const StrVec& rhs){
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    
    auto dest = newdata;
    auto elem = elements;
    for(size_t i=0; i!=size(); ++i){
        alloc.construct(dest++,std::move(*elem++));
    }
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
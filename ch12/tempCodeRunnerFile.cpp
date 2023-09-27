#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <iostream>

class StrBlobPtr;

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

//initializers
StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()){ }
StrBlob::StrBlob(std::initializer_list<std::string> il): 
    data(std::make_shared<std::vector<std::string>>(il)){ }

//define StrBlob functions
void StrBlob::check(size_type i, const std::string &msg) const {
    if(i >= data -> size()){
        throw std::out_of_range(msg);
    }
}

std::string& StrBlob::front() {
    check(0,"front on empty StrBlob");
    return data -> front();
}

const std::string& StrBlob::front() const {
    check(0,"front on empty StrBlob");
    return data -> front();
}

std::string& StrBlob::back() {
    check(0,"back on empty StrBlob");
    return data -> back();
}

const std::string& StrBlob::back() const {
    check(0,"back on empty StrBlob");
    return data -> back();
}

void StrBlob::pop_back() {
    check(0,"pop_back on empty StrBlob");
    data -> pop_back();
}


class StrBlobPtr {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data),curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr(); //prefix version

private:
    //check returns a shared_ptr to the vector if check succeeds
    std::shared_ptr<std::vector<std::string>>
        check(size_type, const std::string&) const;
    
    //store a weak_ptr, so underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; //current position in array


};



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

StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end() {return StrBlobPtr(*this,data -> size());}









void testStrBlob(StrBlob &sb) {
  try {
    sb.push_back("abc");
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    sb.pop_back();
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    sb.begin().deref() = "Change";
    for (auto p = sb.begin(); ; p.incr())
      std::cout << "deref: " << p.deref() << std::endl;
  } catch (std::out_of_range err) {
    std::cerr << err.what() << " out of range" << std::endl;
  } catch (std::exception err) {
    std::cerr << err.what() << std::endl;
  }
}

void testStrBlob(const StrBlob &sb) {
  try {
    std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
  } catch (std::out_of_range err) {
    std::cerr << err.what() << " out of range" << std::endl;
  } catch (std::exception err) {
    std::cerr << err.what() << std::endl;
  }
}

void testStrBlobPtr(StrBlobPtr &sbp) {
  try {
    sbp.deref() = "Change2";
    for (auto p = sbp; ; p.incr())
      std::cout << "deref: " << p.deref() << std::endl;
  } catch (std::out_of_range err) {
    std::cerr << err.what() << " out of range" << std::endl;
  } catch (std::exception err) {
    std::cerr << err.what() << std::endl;
  }
}

int main() {
  StrBlob sb1;
  testStrBlob(sb1);
  std::cout << std::endl;

  StrBlob sb2{"Hello", "World"};
  testStrBlob(sb2);
  std::cout << std::endl;

  const StrBlob csb1;
  testStrBlob(csb1);
  std::cout << std::endl;

  const StrBlob csb2{"This", "Blob"};
  testStrBlob(csb2);
  std::cout << std::endl;

  testStrBlob({"ppp", "qqq"});
  std::cout << std::endl;

  //testStrBlob({"mm", 1});  // Error

  StrBlobPtr sbp1;
  testStrBlobPtr(sbp1);
  std::cout << std::endl;

  StrBlobPtr sbp2(sb1);
  testStrBlobPtr(sbp2);
  std::cout << std::endl;

  StrBlobPtr sbp3(sb1, sb1.size());
  testStrBlobPtr(sbp3);
  std::cout << std::endl;

  StrBlobPtr sbp4(sb2);
  testStrBlobPtr(sbp4);
  std::cout << std::endl;

  StrBlobPtr sbp5(sb2, sb2.size());
  testStrBlobPtr(sbp5);
  std::cout << std::endl;

  return 0;
}
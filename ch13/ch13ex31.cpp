#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class HasPtr {
friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()): 
    ps(new std::string(s)), i(0), use(new std::size_t(1)) { }

    //COPY CONSTRUCTOR
    HasPtr(const HasPtr &orig): 
    ps(new std::string(*orig.ps)), i(orig.i), use(orig.use) {++*use;}

    HasPtr& operator=(const HasPtr &p);
    bool operator<(const HasPtr &rhs) const;

    void set(const std::string &s){
        *ps = s;
    }

    std::string &get(){
        return *ps;
    }

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs){
    ++*rhs.use;
    if(--*use ==0){ //if no other users?
        delete ps;
        delete use;
    }
    ps=rhs.ps;
    i=rhs.i;
    use=rhs.use;
    return *this;
}

void swap(HasPtr &lhs, HasPtr &rhs) {
  std::cout << "Swap between <" << *lhs.ps << "> and <"
            << *rhs.ps << ">" << std::endl;
    //for some reason, vscode is incorrectly labeling std::swap with
  std::swap(lhs.ps, rhs.ps);
  std::swap(lhs.i, rhs.i);
}
bool HasPtr::operator<(const HasPtr &rhs) const {
    return *ps < *rhs.ps;
}


int main(){

    std::string s = "This is a string";
    HasPtr hp1(s);
    HasPtr hp2 = hp1;
    HasPtr hp3(hp1);
    hp1.set("This is a different string");

    std::cout << hp1.get() <<std::endl;
    std::cout << hp2.get() <<std::endl;
    std::cout << hp3.get() <<std::endl;

    HasPtr hp4("This is yet another string");
    swap(hp3,hp4);
    std::cout << hp3.get() <<std::endl;
    std::cout << hp4.get() <<std::endl;

    std::vector<HasPtr> vhp = {hp3,hp2,hp1,hp4};
    std::sort(vhp.begin(),vhp.end());
    for(auto x:vhp){
        std::cout << x.get() <<std::endl;
    }
    


    return 0;
}
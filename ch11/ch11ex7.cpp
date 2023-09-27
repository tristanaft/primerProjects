#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>

typedef std::map<std::string, std::vector<std::string>> family_type;
typedef std::vector<std::string> vecStr;

void addFamily(family_type &families, const std::string &lastName){
    auto check = families.insert({lastName, vecStr()});
    if(!check.second){
        std::cerr << "Error: family " << lastName << " already exists."
        << std::endl;
    }
}
//overload addFamily to accept vector of family names
void addFamily(family_type &families, 
                const vecStr lastNameVector){
    //this is to speed up adding in multiple families at once
    for(std::string lastName : lastNameVector){
        addFamily(families,lastName);
    }
}

void addChild(  family_type &families, const std::string &lastName, 
                const std::string &memberName){
    auto it = families.find(lastName);
    if(it != families.end()){
        it -> second.push_back(memberName);
    }else{
        std::cerr << "Error: family " << lastName << " does not exist for " 
        << "member name: " << memberName << std::endl;
    };
}

//overload addChild to accept vector of member names for a single family
void addChild(family_type &families, const std::string &lastName, 
                const vecStr memberNameVector){
    for(std::string memberName : memberNameVector){
        addChild(families,lastName,memberName);
    }
}

int main(){

    family_type families;

    //try one at a time...
    addFamily(families,"Apple");
    addChild(families,"Apple","Bob");

    vecStr lnvec = {"Baker", "Carlson", "Dover", "Ephriam", "Fawkes"};

    addFamily(families,lnvec);

    vecStr memVec = {"Adam", "Ben", "Chris", "David"};
    addChild(families,"Baker",memVec);

    //lets try to cause an error intentionally
    addFamily(families,"Apple");
    addChild(families,"Wesker","Albert");

    for(const auto &family : families){
        std::cout << family.first << ": ";
        for(const auto &name : family.second){
            std::cout << name <<" ";
        }
        std::cout << std::endl;
    }





    return 0;
}
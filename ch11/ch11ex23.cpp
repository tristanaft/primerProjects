#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>

typedef std::multimap<std::string, std::vector<std::pair<std::string,std::string>>> family_type;
typedef std::vector<std::string> vecStr;

void addFamily(family_type &families, const std::string &lastName){
    families.insert({lastName, std::vector<std::pair<std::string, std::string>>()});
    //auto check = families.insert({lastName, std::vector<std::pair<std::string, std::string>>()});
    //if(!check.second){
    //    std::cerr << "Error: family " << lastName << " already exists."
    //    << std::endl;
    //}
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
                const std::string &memberName, const std::string &birthday){
    auto it = families.find(lastName);
    if(it != families.end()){
        it -> second.push_back({memberName,birthday});
    }else{
        std::cerr << "Error: family " << lastName << " does not exist for " 
        << "member name: " << memberName << std::endl;
    };
}

//overload addChild to accept vector of member names for a single family
void addChild(family_type &families, const std::string &lastName, 
                const vecStr memberNameVector, const vecStr bdayVector){

    //assume memberNameVec and bdayVector are the same length...
    for(auto i=0; i<memberNameVector.size(); i++){
        addChild(families,lastName,memberNameVector[i],bdayVector[i]);
    }
    
}


int main(){

    family_type families;

    //try one at a time...
    addFamily(families,"Apple");
    addChild(families,"Apple","Bob","1-1-2000");
    addChild(families,"Apple","Cammy","1-1-2000");
    addChild(families,"Apple","David","1-1-2000");

    vecStr lnvec = {"Baker", "Carlson", "Dover", "Ephriam", "Fawkes"};

    addFamily(families,lnvec);

    vecStr memVec = {"Adam", "Ben", "Chris", "David"};
    vecStr bdVec = {"1-1-2000","1-2-2000","1-3-2000","1-4-2000"};
    addChild(families,"Baker",memVec, bdVec);


    //lets try to cause an error intentionally
    addChild(families,"Wesker","Albert","12-31-1990");

    for(const auto &family : families){
        std::cout << family.first << ": ";
        for(const auto &name : family.second){
            std::cout << name.first <<" " << name.second <<" ";
            //std::cout << std::endl;
        }
        std::cout << std::endl;
    }





    return 0;
}
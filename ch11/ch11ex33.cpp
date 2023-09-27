#include<string>
#include<iostream>
#include<fstream>
#include<map>
#include<stdexcept>
#include<sstream>

std::map<std::string,std::string> buildMap(std::ifstream &mapFile){

    std::map<std::string,std::string> transMap;
    std::string key, value;
    while(mapFile >> key && std::getline(mapFile,value)){
        if(value.size() > 1){
            transMap[key] = value.substr(1); //put {key,value} in transmap
        }
        else
            throw std::runtime_error("no rule for " + key);
    }
    return transMap;
}

const std::string& transform(const std::string &w, 
                             const std::map<std::string,std::string> &m){
    auto map_it = m.find(w);
    if(map_it != m.cend()){
        return map_it -> second;
    }else{
        return w;
    }
}

void word_transformation(std::ifstream &mapFile, std::ifstream &input){
    auto transMap = buildMap(mapFile);
    std::string text;
    while(std::getline(input,text)){
        std::istringstream stream(text);
        std::string word;
        while(stream >> word){
            std::cout << transform(word,transMap) << " ";
        }
        std::cout << std::endl;

    }
    

}




int main(){

    std::ifstream in("ch11ex33input.in");
    std::ifstream mFile("transformationMap.in");

    word_transformation(mFile, in);



    return 0;
}
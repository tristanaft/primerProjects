#include <map>
#include <iostream>
#include <string>


int main(){

    std::map<std::string, size_t> word_count;
    std::string word;
    while(std::cin >> word){
        //++word_count[word]; other method (easier)
        auto ret = word_count.insert({word,1});
        //ret is pair<pair<string,size_t>, bool>
        if(!ret.second){
            ++ret.first->second;
            //i think ret has a really complicated type...
            //this line looks really weird...
        }
        //It is more obvious with the insert method what is going on...
        //word_count[word] doesn't look like something is being INSERTED
        //if it doesn't exist...
    }



    return 0;
}
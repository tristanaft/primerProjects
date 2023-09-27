#include<iostream>
#include<map>
#include<set>
#include<string>

//just want to try this out...

int main(){

    std::map<std::string, std::size_t> word_count;
    std::set<std::string> exclude = {"The","But","And","Or","An","A",
                                    "the","but","and","or","an","a"};

    std::string word;
    while(std::cin >> word){
        if(word == "(done)") 
            break;

        if(exclude.find(word) == exclude.end())
            ++word_count[word];
        //so, this both adds word to the map and increments the count?
    }
    for(const auto &w : word_count){
        std::cout << w.first << " occurs " << w.second
        << ((w.second > 1) ? " times " : " time ") << std::endl;
    }




    return 0;
}
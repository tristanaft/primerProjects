#include<iostream>
#include<map>
#include<set>
#include<string>

//just want to try this out...

int main(){

    std::map<std::string, std::size_t> word_count;
    std::set<std::string> exclude = {"the","but","and","or","an","a"};
    std::set<std::string> punctuation = {".",",",";",":"};
    //to add: quotation mark removal

    std::cout << "Type something: ";

    std::string word;
    while(std::cin >> word){
        if(word == "(done)") 
            break;

        //change word to lowercase
        word[0]=tolower(word[0]);
        //take off period off the end of the word (if present)
        std::string bk;
        bk += word.back(); //just stick word.back onto the end of string
        //std::cout << bk << " ";
        if(punctuation.find(bk) != punctuation.end()){
            //std::cout << "in if statement ";
            //std::cout << word << " ";
            word.pop_back();
            //std::cout << word << " ";
        }

        //if(word.back() == '.' || word.back() == ',')
        //    word.pop_back();



        if(exclude.find(word) == exclude.end())
            ++word_count[word];
        //so, this both adds word to the map and increments the count?
    }

    std::cout << std::endl;
    for(const auto &w : word_count){
        std::cout << w.first << " occurs " << w.second
        << ((w.second > 1) ? " times " : " time ") << std::endl;
    }




    return 0;
}
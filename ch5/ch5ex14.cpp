#include <iostream>
#include <vector>
#include <string>

int main(){


    std::string s;
    std::vector<std::string> uniqueWords = {};
    std::vector<int> wordCounts = {};
    while(std::cin >> s){

        //if this is the first word, it must be unique:
        if(uniqueWords.size() == 0){
            uniqueWords.push_back(s);
            wordCounts.push_back(1)
            }

        else{ // there is at least one word in uniqueWords

            bool inVector = false; //assume s not in uniqueWords

            unsigned index=0; //keep track of the current index
            for(auto& us : uniqueWords) // for each saved word
            {
                if(s == us){ //input is in unique word vector already
                //increment the corresponding index in wordCounts...
                ++wordCounts[index];
                inVector = true; //s is in uniqueWords now
                }

                ++index; //index goes to next element
            }

            if(inVector = false){ 
            //s is not in uniqueWords, so it must be added
            uniqueWords.push_back(s);
            wordCounts.push_back(1)
            }

        }




    }


    return 1;
}
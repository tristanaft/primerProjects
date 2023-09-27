#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

void printVec(std::vector<std::string> vec){
    for(const auto &s:vec)
        std::cout << s << " ";
    std::cout << std::endl;
}

bool isShorter(const std::string &s1, const std::string &s2){
    return s1.size()<s2.size();
}

void elimDups(std::vector<std::string> &words){

    std::sort(words.begin(),words.end()); //sort so it will be easier to find dupes

    printVec(words);

    auto end_unique = std::unique(words.begin(),words.end());

    printVec(words);

    words.erase(end_unique,words.end());

    printVec(words);

}

int main(){
    std::vector<std::string> vec;
    std::string str;

    std::cout << "Enter some strings: ";
    while(std::cin >> str){
        if(str == "(done)")
            break;
        vec.push_back(str);
    }
    std::cout << std::endl;

    elimDups(vec);

    std::stable_sort(vec.begin(),vec.end(),isShorter);

    printVec(vec);
    //printVec(vec);

    return 0;
}
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

    //printVec(words);

    auto end_unique = std::unique(words.begin(),words.end());

    //printVec(words);

    words.erase(end_unique,words.end());

    //printVec(words);

}

std::string make_plural(size_t ctr, const std::string &word, 
                                    const std::string &ending){
    return (ctr>1) ? word + ending : word;
}


void biggies(   std::vector<std::string> words, //use value instead of ref?
                std::vector<std::string>::size_type sz){

    elimDups(words); //puts words in alphabetical order and elim dupes


    auto wc = std::partition(words.begin(),words.end(),
    [sz](const std::string &w) {return w.size() >= sz;});
    
    //compute number of elements with size greater than sz
    //auto count = wc-words.begin();

    auto count = std::count_if(words.begin(),words.end(),
    [sz](const std::string &w){return w.size() >= sz;});

    std::cout   << count << " " << make_plural(count, "word", "s")
                << " of length " << sz << " or longer" << std::endl;
    
    //print words of given size or longer, each separated by space
    for_each(words.begin(), wc,
    [](const std::string &s){std::cout << s << " ";});

    std::cout << std::endl;




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

    biggies(vec,3);
    std::cout << std::endl;
    biggies(vec,5);

    //printVec(vec);
    //printVec(vec);

    return 0;
}
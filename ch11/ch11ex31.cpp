#include<map>
#include<string>
#include<iostream>



int main(){

    std::multimap<std::string,std::string> bookData = {
        {"Aldous Huxley","Brave New World"},
        {"Ernest Hemmingway","A Farewell to Arms"},
        {"Ernest Hemmingway","The Old Man and the Sea"},
        {"Ray Bradbury", "Fahrenheit 451"},
        {"Jane Austin", "Sense and Sensibility"},
        {"Jane Austin","Pride and Prejudice"},
        {"Kurt Vonnegut","Slaughterhouse-Five"},
        {"Kurt Vonnegut","Cat's Cradle"}
    };

    
    std::cout << "Current Book Data: \n";
    for(auto &p: bookData){
        std::cout << p.first << " " << p.second << std::endl;
    }
    std::string name;
    std::cout << "Enter an author to erase: ";
    std::getline(std::cin, name); //since it is 2 words need getline
    auto it = bookData.find(name);
    if(it == bookData.end()){
        std::cerr << "Author <" << name <<"> not found." << std::endl;
    }
    else{
        bookData.erase(name);
    }
    std::cout << std::endl;

    std::cout << "Current Book Data: \n";
    for(auto &p: bookData){
        std::cout << p.first << " " << p.second << std::endl;
    }




    return 0;
}
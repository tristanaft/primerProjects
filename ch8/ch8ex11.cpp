#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/*
I am lazy and just did file input for 8.11, so I basically did 8.13

*/

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};


int main(){

    std::string fileName = "ch8ex11input.in";
    std::ifstream in(fileName);

    if(in){

        std::string line, word;
        std::vector<PersonInfo> people;
        
        std::istringstream record;

        while(getline(in,line)){
            PersonInfo info;
            record.str(line); //have to manually bind record to the line

            record >> info.name; //read name
            while(record >> word){ // reading phone numbers now
                info.phones.push_back(word);
            }
            people.push_back(info);
            record.clear(); // clear the record of anything
        }


        for(const auto &person: people)
        {
            std::cout << person.name << " ";
            for(const auto &number: person.phones)
            {
                std::cout << number << " ";
            }
            std::cout << std::endl;
        }

    }
    else {
    std::cerr << "Failed to open file: " << fileName << std::endl;
    return -1;
  }

    return 0;
}
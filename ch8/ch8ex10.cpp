#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {

  std::string fileName = "ch8ex10input.in";
  std::ifstream in(fileName);

  if(in){
    std::vector<std::string> vecLines; //vector of lines

    for(std::string line; getline(in,line); vecLines.push_back(line));

    for(const auto &l: vecLines){
        std::istringstream iss(l);
        for(std::string word; iss >> word; std::cout << word << " ");
        std::cout << std::endl;
    }


  } else {
    std::cerr << "Failed to open file: " << fileName << std::endl;
    return -1;
  }

  return 0;
}
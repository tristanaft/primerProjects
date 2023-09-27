#include<iostream>
#include<string>
#include<vector>

class PrintLine{
public:
    std::string operator()(std::istream& is){
        std::string line;
        if(is){
            std::getline(is,line);
            return line;
            vecLines.push_back(line);
        }
        else{
            return line;
        }
    }
private:
    std::vector<std::string> vecLines;
};



int main(){
    PrintLine pl;
    std::cout << "Enter a line: \n";
    std::string test = pl(std::cin);
    std::cout << test << std::endl;


    return 0;
}
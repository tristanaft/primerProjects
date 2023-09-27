#include<iostream>
#include<string>

class PrintLine{
public:
    PrintLine(std::string str = std::string()):
    line(str) {}
    std::string operator()(std::istream& is){
        if(is){
            std::getline(is,line);
            return line;
        }
        else{
            return line;
        }
    }
private:
    std::string line;
};



int main(){
    PrintLine pl;
    std::cout << "Enter a line: \n";
    std::string test = pl(std::cin);
    std::cout << test << std::endl;



    return 0;
}
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

class checkStrLen{
public:
    checkStrLen() = default;
    checkStrLen(std::string::size_type i): val(i) {}
    bool operator()(std::string s) {return s.size() == val;}
private:
    std::string::size_type val;
};

void checkVecStrLen(std::vector<std::string> vs, std::string::size_type i){
    checkStrLen csl(i);
    //I think this should work fine, vscode doesn't like it.
    int c = std::count_if(vs.begin(), vs.end(), csl); 
    if(c == 1){
        std::cout <<"There is "<< c <<" word of length " << i << std::endl;
    }else{
        std::cout <<"There are "<< c <<" words of length " << i << std::endl;
    }
    
}

int main(){

  std::string fileName = "ch14ex38input.in";
  std::ifstream in(fileName);

  std::vector<std::string> vs;
  std::string s;
  while(in >> s){
    vs.push_back(s);
  }

    //checkVecStrLen(std::vector<std::string> vs, std::string::size_type 1)
    for(auto i=1; i<11; ++i ){
        checkVecStrLen(vs, i);
    }









    return 0;
}
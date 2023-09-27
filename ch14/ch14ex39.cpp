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

int countVecStrLen(std::vector<std::string> vs, std::string::size_type i){
    checkStrLen csl(i);
    //I think this should work fine, vscode doesn't like it.
    int c = std::count_if(vs.begin(), vs.end(), csl); 
    return c;
    
}

int main(){

  std::string fileName = "ch14ex39input.in";
  std::ifstream in(fileName);

  std::vector<std::string> vs;
  std::string s;
  while(in >> s){
    vs.push_back(s);
  }

    //checkVecStrLen(std::vector<std::string> vs, std::string::size_type 1)
    int clow = 0;
    for(auto i=1; i<10; ++i ){
        clow += countVecStrLen(vs, i);
    }
    std::cout << "There are " << clow <<" words of length 1-9 and " 
        << (vs.size() - clow) << " words of length 10 or greater." << std::endl;










    return 0;
}
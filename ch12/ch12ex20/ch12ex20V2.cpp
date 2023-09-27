#include "StrBlob.h"
#include "StrBlobPtr.h"
#include<iostream>
#include<fstream>



int main(){

  std::ifstream in("inputFile.in");
  std::string line;

  StrBlob stb;
  for(std::string line; getline(in,line); stb.push_back(line)){}

  StrBlobPtr p = stb.begin();

  for(StrBlob::size_type pos = 0; pos != stb.size(); pos++,p.incr()){
    std::cout << pos+1 <<":\t" << p.deref() << std::endl;
  }


  return 0;
}
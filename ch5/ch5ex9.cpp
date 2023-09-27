#include <iostream>

int main(){

    unsigned aCnt, eCnt, iCnt, oCnt, uCnt;
    
    char ch;
    while(std::cin >> ch){
        if(ch=='a')
            ++aCnt;
        else if(ch=='e')
            ++eCnt;
        else if(ch=='i')
            ++iCnt;
        else if(ch=='o')
            ++oCnt;
        else if(ch=='u')
            ++uCnt;
    }

    std::cout <<"Number of vowel a: \t" << aCnt << '\n';
    std::cout <<"Number of vowel e: \t" << eCnt << '\n';
    std::cout <<"Number of vowel i: \t" << iCnt << '\n';
    std::cout <<"Number of vowel o: \t" << oCnt << '\n';
    std::cout <<"Number of vowel u: \t" << uCnt << std::endl;
    
    
    
    
    
    
    
    
    
    
    
    return 1;}
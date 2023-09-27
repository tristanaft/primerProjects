#include <iostream>

int main(){

    unsigned aCnt, eCnt, iCnt, oCnt, uCnt;
    unsigned spaceCnt, tabCnt, nlCnt;
    
    char ch;
    while(std::cin >> ch){
    switch(ch){

        case 'a': case 'A':
            ++aCnt;
            break;
        case 'e': case 'E':
            ++eCnt;
            break;
        case 'i': case 'I':
            ++iCnt;
            break;
        case 'o': case 'O':
            ++oCnt;
            break;
        case 'u': case 'U':
            ++uCnt;
            break;

        case ' ':
            ++spaceCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++nlCnt;
            break;
    }
    }
    std::cout <<"Number of vowel a: \t" << aCnt << '\n';
    std::cout <<"Number of vowel e: \t" << eCnt << '\n';
    std::cout <<"Number of vowel i: \t" << iCnt << '\n';
    std::cout <<"Number of vowel o: \t" << oCnt << '\n';
    std::cout <<"Number of vowel u: \t" << uCnt << std::endl;

    std::cout << '\n';

    std::cout << "Number of spaces: \t" << spaceCnt << '\n';
    std::cout << "Number of tabs: \t" << tabCnt << '\n';
    std::cout << "Number of new lines: \t" << nlCnt << '\n';
    
    
    
    
    
    
    
    
    
    
    
    return 1;}
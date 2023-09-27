#include "TextQuery.h"
#include "QueryResult.h"

void TextQuery::addToMap(std::string word,int lineNumber){
    //check if word is currently in the map
    auto check = wordOccurrences.find(word);
    if(check == wordOccurrences.end()){
        //word is not in wordOccurences
        wordOccurrences.insert({word, {lineNumber}});
    }else{
        //word is currently in wordOccurrences
        //add lineNumber to the vector of occurrences

        //WHAT IF MULTIPLE TIMES IN ONE LINE
        //just have to have that integer appear multiple times,
        //otherwise how can I get total count of the number of occurrences?
        check -> second.push_back(lineNumber);
    }

}

void TextQuery::printText(){
    for(auto l : entireText) 
    std::cout << l << std::endl;
}

TextQuery::TextQuery(std::ifstream& in){
    int lineCount = 0;
    for(std::string line; getline(in,line);){//for each line in source file;
        entireText.push_back(line);
        
        std::istringstream iss(line); //have string stream for line
        std::string word;
        while(iss >> word){
            addToMap(word,lineCount);
      }
      lineCount++;
    }
}

QueryResult TextQuery::query(std::string target){
    auto result = wordOccurrences.find(target);
    auto tc = result ->second.size();
    //convert the line number vector into a SET
    std::set<int> lineSet;
    for(int i : result -> second) lineSet.insert(i);


    //need to build vector of lines that need to be sent
    std::vector<std::string> queryLines;
    for(int lineNum : result -> second){
        queryLines.push_back(entireText[lineNum]);
    }

    return QueryResult(tc, target, lineSet, queryLines);

}

//QueryResult(int tc, std::string qw, std::vector<int> ln, std::vector<std::string> ql):
//totalCount(tc), queryWord(qw), lineNumbers(ln), queryLines(ql) { }
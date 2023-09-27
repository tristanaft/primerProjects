#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

//define function to read file and read contents
//into vector of strings...

vector<string> read(const string fileName){
    std::ifstream in(fileName);

    string word;
    vector<string> myWords;

    if(in){ //if the stream is valid
        while(in){ //read stream
            in >> word;
            myWords.push_back(word);
        }
    }
    else{ //stream is invalid
        cout << "No file!" << endl;
    }

    


    return myWords;
}



int main(){
    //cout << "Input file name: ";
    //string fileName;
    //cin >> fileName;
    string fileName = "ch8ex4input.in";
    vector<string> vec = read(fileName);
    for(string s:vec){
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}
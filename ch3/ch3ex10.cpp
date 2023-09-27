#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;


int main()
{

    string str; //read input line by line
    cout<< "Enter a string and this program will remove any punctuation" << endl;

    cin >> str;

    for(const auto &c : str) 
        if(!ispunct(c)) 
            cout << c;
    cout << endl;
    

return 0;
}
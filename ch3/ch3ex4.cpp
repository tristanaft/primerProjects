#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;


int main()
{

    string word; //read input by word
    string combination; // all the words mashed together
    while (cin>>word && word != "stop")
    {
        combination += word;                        
    }
    cout << combination << endl; 

return 0;
}
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;


int main()
{

    string word; //read input by word
    while (cin>>word && word != "stop")
    {
        cout << word << endl;                         
    }

return 0;
}
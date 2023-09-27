#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;


int main()
{

    string str = "arbitrary";
    cout << str << endl;


    for(auto &c : str)
    c = 'X';
    cout << str << endl;



return 0;
}
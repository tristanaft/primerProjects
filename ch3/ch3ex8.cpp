#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;


void change_with_for()
{
    string str = "arbitrary";
    cout << str << endl;
    
    for(
        decltype(str.size()) idx = 0;
        idx!=str.size();
        idx++)
    {
        //cout<<idx;
        str[idx] = 'X';
    }

    cout << str << endl;

}

void change_with_while()
{
    string str = "arbitrary";
    cout << str << endl;
    decltype(str.size()) idx = 0;
    
    while(idx != str.size())
    {
        //cout<<idx;
        str[idx] = 'X';
        ++idx;
    }

    cout << str << endl;

}


int main()
{
    //change_with_for();
    change_with_while();

return 0;
}
#include <iostream>
#include <string>

using std::string;

bool hasCapital(const string& str)
{
    bool hasCap = false;
    for(const char&c : str){
        if(isupper(c))
            hasCap = true;
    }

    return hasCap;
}

void stringToLower(string& str)
{
    for(char& c : str)
    {
        if(isupper(c))
            c=tolower(c);
    }

}


int main()
{
    string s = "This is a String with CAPITAL LETTERS";
    std::cout << s << "\n";

    std::cout << hasCapital(s) << "\n";

    stringToLower(s);

    std::cout << s << "\n";

    return 0;
}
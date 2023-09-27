#include <string>

using std::string;

//this code is intentionally incorrect

bool str_subrange(const string &str1,const string &str2)
{
    //same sizes: return equality test
    if(str1.size() == str2.size())
        return str1==str2; //ok returns bool
    
    auto size = (str1.size() < str2.size()) ?str1.size() :str2.size();

    for(decltype(size) i = 0; i!= size; i++)
    {
        if (str1[i] != str2[i])
            return; //this return should spit out an error
    }
    //lack of return here probably wont spit out an error
}
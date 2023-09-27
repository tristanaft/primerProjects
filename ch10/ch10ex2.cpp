#include<algorithm>
#include<iostream>
#include<list>
#include<string>


int main(){

    std::list<std::string> ls;

    std::cout << "Enter some strings: ";
    std::string str;
    while(std::cin >> str){
        if(str == "(done)")
            break;
        ls.push_back(str);
    }
    std::cout << std::endl;

    //to prompt user again, need to clear stream
    //and ignore empty space...
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string target;
    std::cout << "Now, enter a target string to count: ";
    std::cin >> target;

    auto bg = ls.begin();
    auto en = ls.end();
    int cn = std::count(ls.begin(),ls.end(),target);

    std::cout<< "The string: " << target << " appears " << cn <<
        " times." << std::endl;






    return 0;
}
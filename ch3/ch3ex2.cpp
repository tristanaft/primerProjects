#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;


int main()
{

    string line; //read input line by line
    while (getline(cin,line))
    {
        if (line.size() > 80) //output to terminal if greater than 80
        {
            cout << line << endl;   //no way to break out of loop,
                                    //so use command C
        }
    }

return 0;
}